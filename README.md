# Questions about C++ refactoring

## Initial project

This could be the initial project.

```
src
 |-ElectricalConnectorContact.h
 |-ElectricalConnector.h
 |-ElectricalConnector.cpp
tests
 |-src
    |-ElectricalConnectorTest.cpp
```

`ElectricalConnector.h`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#ifndef MDT_ELECTRICAL_CONNECTOR_H
#define MDT_ELECTRICAL_CONNECTOR_H

#include "ElectricalConnectorContact.h"

/*! \brief API doc
 */
class ElectricalConnector
{
 public:

  ElectricalConnector() noexcept;
};

#endif // #ifndef MDT_ELECTRICAL_CONNECTOR_H
```

`ElectricalConnector.cpp`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#include "ElectricalConnector.h"

ElectricalConnector::ElectricalConnector()
{
}
```

While working on the project, we want to extract some classes and put them to a library.
We rename a class, put it to a namespace.

## After refactoring



```
libs
 |-Mdt
    |-ElectricalConnectorLibrary
         |
        src
         |-ConnectorContact.h
         |-Connector.h
         |-Connector.cpp
        tests
         |-src
            |-ConnectorTest.cpp
```

`Connector.h`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#ifndef MDT_ELECTRICAL_CONNECTOR_LIBRARY_CONNECTOR_H
#define MDT_ELECTRICAL_CONNECTOR_LIBRARY_CONNECTOR_H

#include "Mdt/ElectricalConnectorLibrary/ConnectorContact.h"
#include "mdt_electricalconnectorlibrary_export.h"

namespace Mdt{ namespace ElectricalConnectorLibrary{

  /*! \brief API doc
   */
  class MDT_ELECTRICCONNECTORLIBRARY_EXPORT Connector
  {
   public:

    Connector() noexcept;
  };

}} // namespace Mdt{ namespace ElectricalConnectorLibrary{

#endif // #ifndef MDT_ELECTRICAL_CONNECTOR_LIBRARY_CONNECTOR_H
```

`Connector.cpp`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#include "Connector.h"

namespace Mdt{ namespace ElectricalConnectorLibrary{

Connector::Connector()
{
}

}} // namespace Mdt{ namespace ElectricalConnectorLibrary{
```

`ConnectorTest.cpp`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#include "catch2/catch.hpp"
#include "Mdt/ElectricalConnectorLibrary/Connector.h"

using namespace Mdt::ElectricalConnectorLibrary;

TEST_CASE("SomeTest")
{
  Connector connector = ...
}
```
