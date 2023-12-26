// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_ALGORITHM_H
#define MDT_CPP_REFACTORING_ALGORITHM_H

#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <QChar>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief 
   */
  void transformCamelCaseString() noexcept;

  /*! \brief 
   */
  void camelCaseStringToParts() noexcept;

  /*! \brief Applies the given function object \a f to the result of dereferencing every pair of adjacent iterators in the range [\a first, \a last)
   *
   * This function template is similar to [std::for_each()](http://en.cppreference.com/w/cpp/algorithm/for_each),
   *  but it calls \a f for each adjacent iterators \a first and \a first + 1.
   *
   * The iterator types are mutable, f may modify the elements of the range trough the dereferenced iterator.
   *  If f returns a result, the result is ignored.
   *
   * \tparam ForwardIt Type of a iterator that meets the requirement of [ForwardIterator](https://en.cppreference.com/w/cpp/named_req/ForwardIterator).
   * \tparam BinaryFunction A function object with a signature equivalent to:
   *          \code
   *          void f(const Type & a, const Type & b);
   *          \endcode
   *
   * Example:
   * \code
   * std::vector<int> inVector{1,2,3,4,5};
   * std::vector<int> outVector;
   *
   * const auto f = [&outVector](int a, int b){
   *   outVector.push_back(a+b);
   * };
   *
   * Mdt::Algorithm::forEachAdjacentPair(inVector.cbegin(), inVector.cend(), f);
   *
   * // outVector: {3,5,7,9}
   * \endcode
   */
  template<typename ForwardIt, typename BinaryFunction>
  constexpr void forEachAdjacentPair(ForwardIt first, ForwardIt last, BinaryFunction f)
  {
    if(first != last){
      auto trailer = first;
      ++first;
      while(first != last){
        f(*trailer, *first);
        ++first;
        ++trailer;
      }
    }
  }

  /*! \brief Append a char comming from a camel case string to a upper case snake string
   *
   * Appends \a current as upper case to \a out .
   *
   * If \a previous is lower case and \a current is upper case,
   * an underscore will also be appended to \a out before \a current .
   *
   * Examples:
   * \code
   * previous:p, current:R -> _R
   * previous:C, current:p -> P
   * \endcode
   */
  MDT_CPPREFACTORING_EXPORT
  void appendCamelCaseCharToSnakeCaseUpperString(QChar previous, QChar current, QString & out) noexcept;

  /*! \brief Returns a UPPER_SNAKE_CASE_STRING from a given CamelCaseString
   *
   * For each case change from lower to upper case,
   * an underscore will be inserted.
   *
   * This is not done when changing from upper to lower case.
   *
   * Examples:
   * \code
   * Mdt -> MDT
   * CppRefactoring -> CPP_REFACTORING
   * \endcode
   */
  MDT_CPPREFACTORING_EXPORT
  QString snakeCaseUpperStringFromCamelCaseString(const QString & camelString) noexcept;
  // QString camelCaseStringToSnakeCaseUpperString(const QString & camelString) noexcept;

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_ALGORITHM_H
