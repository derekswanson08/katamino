#include <algorithm>
#include "pent.h"

using namespace std;

const char BLANK = '.';
const char OVERLAP = '$';
const int LEVEL = 8;

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

vector<shared_ptr<Pent>> Pent::conv(const Pent& src1, const Pent& src2)
{
    vector<shared_ptr<Pent>> r;

    auto list1 = src1.allRotations();
    auto list2 = src2.allRotations();

    for(auto r1 : list1)
    {
        for(auto r2 : list2)
        {
            // Pad r1 such that r2 can fit on all four sides
            Pent p1(r1->m_height + 2*r2->m_height, r1->m_width + 2*r2->m_width);
            copy(p1, *r1, r2->m_width, r2->m_height);

            for(int y = 0; y <= (p1.m_height - r2->m_height); y++)
            {
                for(int x = 0; x <= (p1.m_width - r2->m_width); x++)
                {
                    // Copy r2 to the offset
                    Pent p2(p1.m_height, p1.m_width);
                    copy(p2, *r2, x, y);
                    auto p3 = make_shared<Pent>();
                    *p3 = add(p1, p2);
                    p3->trim();
                    if(p3->isLegal())
                    {
                        r.push_back(p3);
                    }
                }
            }
        }
    }

    r = removeDuplicates(r);
    std::sort(r.begin(),r.end(),[](shared_ptr<Pent> a, shared_ptr<Pent> b) {
        return a->size() < b->size();
    });
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

Pent Pent::trim(const Pent& src)
{
    int min_x = src.m_width-1;
    int min_y = src.m_height-1;
    int max_x = 0;
    int max_y = 0;
    for(int y = 0; y < src.m_height; y++)
    {
        for(int x = 0; x < src.m_width; x++)
        {
            if(src.at(x,y) != BLANK)
            {
                min_x = std::min(min_x, x);
                max_x = std::max(max_x, x);
                min_y = std::min(min_y, y);
                max_y = std::max(max_y, y);
            }
        }
    }
    int height = max_y - min_y + 1;
    int width = max_x - min_x + 1;
    Pent r = crop(src, height, width, min_x, min_y);
    return r;
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

void Pent::trim(void)
{
    *this = trim(*this);
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

std::shared_ptr<Pent> solve(std::vector<Pent> list, Pent board, bool verbose)
{
    if(list.size() > 0)
    {
        Pent pentToPlace = list.back();
        list.pop_back();
        auto rotations = pentToPlace.allRotations();
        for(size_t ii = 0; ii < rotations.size(); ii++)
        {
            std::shared_ptr<Pent> p = rotations[ii];
            if(verbose)
            {
                printf("%lu/%lu\n", ii, rotations.size());
            }
            for(int x = 0; x <= (board.width() - p->width()); x++)
            {
                for(int y = 0; y <= (board.height() - p->height()); y++)
                {
                    Pent newBoard = Pent::add(board, *p, x, y);
                    if(newBoard.isLegal())
                    {
                        auto solution = solve(list, newBoard, false);
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
        printf("=========================\n");
        printf("=========================\n");
        printf("=== solved it!!! ========\n");
        board.print();
        printf("=========================\n");
        printf("=========================\n");
        return std::make_shared<Pent>(board);
    }
    return nullptr;
}

int main(void)
{
    vector<Pent> k;
    k.emplace_back(4,2);
    k.back().setString(
        "0."
        "0."
        "0."
        "00");

    k.emplace_back(4,2);
    k.back().setString(
        ".1"
        ".1"
        "11"
        "1.");

    k.emplace_back(3,2);
    k.back().setString(
        "22"
        "22"
        "2.");

    k.emplace_back(3,3);
    k.back().setString(
        "33."
        ".3."
        ".33");

    k.emplace_back(3,3);
    k.back().setString(
        "444"
        ".4."
        ".4.");

//    k.emplace_back(4,2);
//    k.back().setString(
//        ".5"
//        "55"
//        ".5"
//        ".5");

    k.emplace_back(3,3);
    k.back().setString(
        "..6"
        "..6"
        "666");

    k.emplace_back(2,3);
    k.back().setString(
        "7.7"
        "777");

    k.emplace_back(3,3);
    k.back().setString(
        ".88"
        "88."
        ".8.");

//    k.emplace_back(3,3);
//    k.back().setString(
//        "..9"
//        ".99"
//        "99.");
//
//    k.emplace_back(3,3);
//    k.back().setString(
//        ".a."
//        "aaa"
//        ".a.");
//    k.emplace_back(1,5);
//    k.back().setString(
//        "bbbbb");
    
#if 0
    printf("---k[0]--\n");
    k[0].print();
    printf("\n");

    printf("---k[1]--\n");
    k[1].print();
    printf("\n");

    auto list = Pent::conv(k[0],k[1]);
    for(auto p : list)
    {
        printf("---------\n");
        p->print();
        printf("\n");
    }
    printf("total = %lu\n",list.size());
#endif

    Pent board(5, k.size());
    solve(k, board, false);

}


void Pent::crop(int height, int width, int xOffset, int yOffset)
{
    *this = crop(*this, height, width, xOffset, yOffset);
}

Pent Pent::crop(const Pent& src, int height, int width, int xOffset, int yOffset)
{
    assert((height+yOffset) <= src.m_height);
    assert((width+xOffset) <= src.m_width);
    Pent r(height, width);
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            r.at(x,y) = src.at(x+xOffset, y+yOffset);
        }
    }
    return r;
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

// 012   630
// 345   741
// 678   852

// 0123  840
// 4567  951
// 89ab  a62
//       b73

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

