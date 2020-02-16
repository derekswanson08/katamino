#pragma once

#include <string>
#include <vector>
#include <memory>

class Runner;

class Pent
{
    public:
        Pent(void) = default;
        Pent(int h, int w);
        void print(void) const;
        void setString(const std::string& s);
        void add(const Pent& other);
        void rotate(void);
        void fliplr(void);
        void flipud(void);
        bool isLegal(void) { return m_isLegal; }
        std::vector<std::shared_ptr<Pent>> allRotations(void) const;

        char& at(int x, int y);
        const char& at(int x, int y) const;

        static Pent add(const Pent& src1, const Pent& src2);
        static Pent add(const Pent& board, const Pent& pent, int xOffset, int yOffset);
        static void copy(Pent& dst, const Pent& src, int xOffset, int yOffset);
        static Pent rotate(const Pent& src);
        static Pent fliplr(const Pent& src);
        static Pent flipud(const Pent& src);

        static std::shared_ptr<Pent> solve(std::vector<Pent> list, Pent board, Runner* runner);

        bool operator==(const Pent& rhs) const;
        bool operator!=(const Pent& rhs) const { return !(*this == rhs); }

        int size() const { return m_height * m_width; }
        int width() const { return m_width; }
        int height() const { return m_height; }
    
    private:
        std::string m_data;
        int m_height = 0;
        int m_width = 0;
        bool m_isLegal = true;
};

