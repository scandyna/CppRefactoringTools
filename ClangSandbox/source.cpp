// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/


struct ThisThinksThatTopCommentBlockIsApiDoc
{
};

void plainFunction()
{
}

/*! \brief C doc
 */
class C
{
 public:

  void f();
};

void C::f()
{
}

namespace A{

  /*! \brief This is A::C
   */
  class C
  {
  };

} // namespace A{
