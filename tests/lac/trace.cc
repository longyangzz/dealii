// ---------------------------------------------------------------------
//
// Copyright (C) 2005 - 2018 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


// check FullMatrix::trace


#include <deal.II/lac/full_matrix.h>

#include "../tests.h"



int
main()
{
  std::ofstream logfile("output");
  deallog << std::fixed;
  deallog << std::setprecision(0);
  deallog.attach(logfile);

  const unsigned int N = 20;
  FullMatrix<double> m(N, N);

  double tr = 0;
  for (unsigned int i = 0; i < N; ++i)
    for (unsigned int j = 0; j < N; ++j)
      {
        m(i, j) = i + j;
        if (i == j)
          tr += i + j;
      }

  deallog << "Trace=" << m.trace() << std::endl;
  Assert(m.trace() == tr, ExcInternalError());
}
