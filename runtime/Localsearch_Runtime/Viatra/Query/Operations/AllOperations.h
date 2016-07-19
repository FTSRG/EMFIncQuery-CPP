#pragma once

/**
 * @file This file includes every implemented search operation.
 */

#include "ISearchOperation.h"

// include all operations
// check
#include "Check/InstanceOfCheck.h"
#include "Check/AssociationCheck.h"
#include "Check/CheckExpression.h"
#include "Check/NACOperation.h"
#include "Check/TransitiveClosureCheck.h"

//extend
#include "Extend/IterateOverInstances.h"
#include "Extend/NavigateAssociation.h"
