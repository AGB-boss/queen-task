#include "classes.h"


namespace Chess
{

const Solution Solution::m_emptyObject = {};

Solution::Solution(const Solution &src)
    : m_final(src.isFinal())
{

}

Solution Solution::makeChildSolution() const
{
    return Solution();
}

void SolutionHash::addPiece(BoardCell cell)
{
}

} // end namespace Chess
