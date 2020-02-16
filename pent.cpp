#include <algorithm>
#include <QThread>
#include "pent.h"
#include "runner.h"

using namespace std;

static const char BLANK = '.';
static const char OVERLAP = '$';

Pent::Pent(int h, int w) :
        m_height(h),
        m_width(w)
{
    m_data.resize(h*w,BLANK);
}

void Pent::print(void) const
{
    assert((m_height*m_width) == m_data.size());
    for(int y = 0; y < m_height; y++)
    {
        for(int x = 0; x < m_width; x++)
        {
            printf("%c",at(x,y));
        }
        printf("\n");
    }
}

void Pent::setString(const std::string& s)
{
    m_data = s;
}

bool contains(const std::vector<std::shared_ptr<Pent>>& v, std::shared_ptr<Pent> x)
{
    for(auto p : v) 
    {
        if(*p == *x)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Pent>> removeDuplicates(const std::vector<std::shared_ptr<Pent>>& x)
{
    std::vector<std::shared_ptr<Pent>> r;
    for(auto p : x)
    {
        if(!contains(r, p))
        {
            r.push_back(p);
        }
    }
    return r;
}

void Pent::copy(Pent& dst, const Pent& src, int xOffset, int yOffset)
{
    for(int y = 0; y < src.m_height; y++)
    {
        int yy = y + yOffset;
        if((0 <= yy) && (yy < dst.m_height))
        {
            for(int x = 0; x < src.m_width; x++)
            {
                int xx = x + xOffset;
                if((0 <= xx) && (xx < dst.m_width))
                {
                    dst.at(xx,yy) = src.at(x,y);
                }
            }
        }
    }
}

Pent Pent::add(const Pent& src1, const Pent& src2)
{
    assert(src1.m_width == src2.m_width);
    assert(src1.m_height == src2.m_height);
    assert(src1.m_data.size() == src2.m_data.size());
    Pent r;
    r.m_width = src1.m_width;
    r.m_height = src1.m_height;
    r.m_isLegal = src1.m_isLegal && src2.m_isLegal;
    r.m_data.resize(src1.m_data.size());
    for(size_t ii = 0; ii < src1.m_data.size(); ii++)
    {
       char out;
       char c1 = src1.m_data[ii];
       char c2 = src2.m_data[ii];
       if(c1 == BLANK)
       {
           if(c2 == BLANK)
           {
               out = BLANK;
           }
           else
           {
               out = c2;
           }
       }
       else
       {
           if(c2 == BLANK)
           {
               out = c1;
           }
           else
           {
               out = OVERLAP;
               r.m_isLegal = false;
           }
       }
       r.m_data[ii] =  out;
    }
    return r;
}

Pent Pent::add(const Pent& board, const Pent& pent, int xOffset, int yOffset)
{
    assert((pent.m_width + xOffset) <= board.m_width);
    assert((pent.m_height + yOffset) <= board.m_height);
    Pent r = board;
    r.m_isLegal = board.m_isLegal && pent.m_isLegal;
    for(int y = 0; y < pent.m_height; y++)
    {
        for(int x = 0; x < pent.m_width; x++)
        {
            char out;
            char c1 = pent.at(x, y);
            char c2 = board.at(x + xOffset, y + yOffset);
            if(c1 == BLANK)
            {
                if(c2 == BLANK)
                {
                    out = BLANK;
                }
                else
                {
                    out = c2;
                }
            }
            else
            {
                if(c2 == BLANK)
                {
                    out = c1;
                }
                else
                {
                    out = OVERLAP;
                    r.m_isLegal = false;
                }
            }
            r.at(x + xOffset, y + yOffset) = out;
        }
    }
    return r;
}

char& Pent::at(int x, int y)
{
    assert((0 <= x) && (x < m_width));
    assert((0 <= y) && (y < m_height));
    return m_data[(y * m_width) + x];
}

const char& Pent::at(int x, int y) const
{
    assert((0 <= x) && (x < m_width));
    assert((0 <= y) && (y < m_height));
    return m_data[(y * m_width) + x];
}

std::shared_ptr<Pent> Pent::solve(std::vector<Pent> list, Pent board, Runner* runner)
{
    if(list.size() > 0)
    {
        Pent pentToPlace = list.back();
        list.pop_back();
        auto rotations = pentToPlace.allRotations();
        for(std::shared_ptr<Pent> p : rotations)
        {
            for(int x = 0; x <= (board.width() - p->width()); x++)
            {
                for(int y = 0; y <= (board.height() - p->height()); y++)
                {
                    Pent newBoard = Pent::add(board, *p, x, y);
                    if(newBoard.isLegal())
                    {
                        //QThread::msleep(1);
                        runner->update(newBoard, false);
                        auto solution = solve(list, newBoard, runner);
                        if(solution != nullptr)
                        {
                            return solution;
                        }
                    }
                }
            }
        }
    }
    else
    {
        return std::make_shared<Pent>(board);
    }
    return nullptr;
}


std::vector<std::shared_ptr<Pent>> Pent::allRotations(void) const
{
    std::vector<std::shared_ptr<Pent>> r;

    Pent p = *this;
    for(int ii = 0; ii < 4; ii++)
    {
        r.push_back(make_shared<Pent>());
        *r.back() = p;
        p.rotate();
    }

    p = flipud(*this);
    for(int ii = 0; ii < 4; ii++)
    {
        r.push_back(make_shared<Pent>());
        *r.back() = p;
        p.rotate();
    }

    p = fliplr(*this);
    for(int ii = 0; ii < 4; ii++)
    {
        r.push_back(make_shared<Pent>());
        *r.back() = p;
        p.rotate();
    }

    return removeDuplicates(r);
}

void Pent::rotate(void)
{
    *this = rotate(*this);
}

Pent Pent::rotate(const Pent& src)
{
    int h = src.m_width;
    int w = src.m_height;
    Pent r(h,w);
    for(int y = 0; y < src.m_height; y++)
    {
        int xx = src.m_height - 1 - y;
        for(int x = 0; x < src.m_width; x++)
        {
            int yy = x;
            r.at(xx,yy) = src.at(x,y);
        }
    }
    return r;
}

bool Pent::operator==(const Pent& rhs) const
{
    if(m_data.size() != rhs.m_data.size())
    {
        return false;
    }
    for(size_t ii = 0; ii < m_data.size(); ii++)
    {
        char c1 = m_data[ii];
        char c2 = rhs.m_data[ii];
        if((c1 == BLANK) && (c2 != BLANK))
        {
            return false;
        }
        if((c1 != BLANK) && (c2 == BLANK))
        {
            return false;
        }
    }
    if(m_height != rhs.m_height)
    {
        return false;
    }
    if(m_width != rhs.m_width)
    {
        return false;
    }
    return true;
}

void Pent::fliplr(void)
{
    *this = fliplr(*this);
}

void Pent::flipud(void)
{
    *this = flipud(*this);
}

Pent Pent::fliplr(const Pent& src)
{
    Pent r(src.m_height, src.m_width); 
    for(int y = 0; y < src.m_height; y++)
    {
        for(int x = 0; x < src.m_width; x++)
        {
            int xx = src.m_width - 1 - x;
            r.at(xx, y) = src.at(x, y);
        }
    }
    return r;
}

Pent Pent::flipud(const Pent& src)
{
    Pent r(src.m_height, src.m_width); 
    for(int y = 0; y < src.m_height; y++)
    {
        int yy = src.m_height - 1 - y;
        for(int x = 0; x < src.m_width; x++)
        {
            r.at(x, yy) = src.at(x, y);
        }
    }
    return r;
}

