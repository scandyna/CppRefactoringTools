

```
libs
 |-Mdt
    |-ElectricConnectorLibrary
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
#ifndef MDT_ELECTRIC_CONNECTOR_LIBRARY_H
#define MDT_ELECTRIC_CONNECTOR_LIBRARY_H

#include "Mdt/ElectricConnectorLibrary/ConnectorContact.h"
#include "mdt_electricconnectorlibrary_export.h"

namespace Mdt{ namespace ElectricConnectorLibrary{

  /*! \brief API doc
   */
  class MDT_ELECTRICCONNECTORLIBRARY_EXPORT Connector
  {
   public:

    Connector() noexcept;
  };

}} // namespace Mdt{ namespace ElectricConnectorLibrary{

#endif // #ifndef MDT_ELECTRIC_CONNECTOR_LIBRARY_H
```

`Connector.cpp`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#include "Connector.h"

namespace Mdt{ namespace ElectricConnectorLibrary{

Connector::Connector()
{
}

}} // namespace Mdt{ namespace ElectricConnectorLibrary{
```

`ConnectorTest.cpp`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#include "catch2/catch.hpp"
#include "Mdt/ElectricConnectorLibrary/Connector.h"

using namespace Mdt::ElectricConnectorLibrary;

TEST_CASE("SomeTest")
{
  Connector connector = ...
}
```
