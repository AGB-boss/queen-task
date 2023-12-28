#ifndef classes_H
#define classes_H

#include <array>
#include <vector>

using namespace std;

namespace Chess
{
constexpr size_t BOARD_HEIGHT = 8;
constexpr size_t BOARD_WIDTH = 8;

 array< array<int, BOARD_HEIGHT>, BOARD_WIDTH> CellsBoard;

class BoardCell
{
public:
    int m_row;
    int m_column;
};
class CellsSet
{
public: 
    void addCell(BoardCell cell);
private:

};

class SolutionsSet;
class Solution
{
public:
    static int getMaxPiecesInSolution() {}
    
    Solution() : m_final(false) {}

    Solution(const Solution& parent);

    /// @brief  Make new solution by adding new piece to already
    ///         existing pieces on the board
    /// @return 
    Solution makeChildSolution() const;

    /// @brief 
    /// @return reference to the set of child solutions 
    SolutionsSet& childSolutions() { return m_childSolutions; }

    inline bool isFinal() const { return m_final; }

    static const Solution& emptyObject() { return m_emptyObject; }
private:
    bool m_final;
    SolutionsSet m_childSolutions;

    static const Solution m_emptyObject;
};

class SolutionsSet
{
public:
    SolutionsSet() {}

    const Solution& parentSolution() { return *m_parentSolution; }
private:
    const Solution* m_parentSolution;
};

vector<Solution>& minSolutions()
{
    static vector<Solution> m_minSolutions;
    return m_minSolutions;
}
vector<Solution>& maxSolutions()
{
    static vector<Solution> m_maxSolutions;
    return m_maxSolutions;
}

}// end namespace Chess
#endif// classes_H