#pragma once

#include <string>
#include <vector>
#include <memory>

class Pent
{
    public:
        Pent(void) = default;
        Pent(int h, int w);
        void print(void) const;
        void setString(const std::string& s);
        void add(const Pent& other);
        void trim(void);
        void crop(int height, int width, int xOffset, int yOffset);
        void rotate(void);
        void fliplr(void);
        void flipud(void);
        bool isLegal(void) { return m_isLegal; }
        std::vector<std::shared_ptr<Pent>> allRotations(void) const;

        char& at(int x, int y);
        const char& at(int x, int y) const;

        static std::vector<std::shared_ptr<Pent>> conv(const Pent& src1, const Pent& src2);
        static Pent add(const Pent& src1, const Pent& src2);
        static Pent add(const Pent& board, const Pent& pent, int xOffset, int yOffset);
        static void copy(Pent& dst, const Pent& src, int xOffset, int yOffset);
        static Pent trim(const Pent& src);
        static Pent crop(const Pent& src, int height, int width, int xOffset, int yOffset);
        static Pent rotate(const Pent& src);
        static Pent fliplr(const Pent& src);
        static Pent flipud(const Pent& src);

        bool operator==(const Pent& rhs) const;
        bool operator!=(const Pent& rhs) const { return !(*this == rhs); }

        int size() { return m_height * m_width; }
        int width() { return m_width; }
        int height() { return m_height; }
    
    private:
        std::string m_data;
        int m_height = 0;
        int m_width = 0;
        bool m_isLegal = true;
};

