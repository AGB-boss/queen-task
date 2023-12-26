#ifndef classes_H
#define classes_H

#include <vector>

using namespace std;

namespace Chess
{

class PiecesSet // representation of set of pieces (queens)
{
public:
    bool addPiece();
};

class Solution
{
public:
    static int getMaxPiecesInSolution() {}
    
    Solution()
    {}
    Solution(const Solution& src);
private:
};

class SolutionsSet
{
public:
    SolutionsSet() {}

    const Solution& getBestSolution();

private:
    const Solution* m_bestSolution = &m_pVoidSolution;
    static const Solution m_voidSolution = {};
};

}// end namespace Chess
#endif// classes_H