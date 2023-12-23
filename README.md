# Questions about C++ refactoring

[[_TOC_]]

# Introduction

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
#ifndef ELECTRICAL_CONNECTOR_H
#define ELECTRICAL_CONNECTOR_H

#include "ElectricalConnectorContact.h"

/*! \brief API doc
 */
class ElectricalConnector
{
 public:

  ElectricalConnector() noexcept;
};

#endif // #ifndef ELECTRICAL_CONNECTOR_H
```

`ElectricalConnector.cpp`:
```CPP
// SPDX-ID
/*
 * Some header comment
 */
#include "ElectricalConnector.h"

ElectricalConnector::ElectricalConnector() noexcept
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
         |-src
         |  |-ConnectorContact.h
         |  |-Connector.h
         |  |-Connector.cpp
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

Connector::Connector() noexcept
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

# Status

Creating a class would be the first thing to implement.

Editing CMakeLists.txt is currently not planned.

# Concepts

## Class

Regroups all attributes required to create or rename a class.

## ClassName

The name of the class.
Will be used for ither attributes.

## ClassHeaderFileName

## ClassSourceFileName

## TestName

## TestSourceFileName

## Namespace

## IncludeGuard

## HeaderFile

## SourceFile

## FileSystemStructure


## UsageConanFile

## DeployConanFile

# Use cases

## Create a blank project

## Create a class

The user provides a class name.

The source file names are proposed,
based on the class name:
- ClassName.h
- ClassName.cpp

A test name is also proposed:
- ClassNameTest.cpp

Optionaly, the class can be in a namespace.
The user can provide a namespace:
```
Mdt::ElectricalConnectorLibrary
```

#TODO: the test should also include the class and define using namespace x::y;
