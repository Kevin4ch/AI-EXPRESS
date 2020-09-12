/**
 * @file method_factory.cpp
 * @author your name (you@domain.com)
 * @brief DO NOT MODIFY THIS FILE, WHICH IS AUTO GENERATED BY COMPILER
 * @version 0.1
 * @date 2018-11-23
 *
 * @copyright Copyright (c) 2018
 *
 */

#include "hobotxstream/method_factory.h"
#include <string>
#include "CNNMethod/CNNMethod.h"
#include "FasterRCNNMethod/FasterRCNNMethod.h"
#include "MOTMethod/MOTMethod.h"
#include "GradingMethod/GradingMethod.h"
#include "SnapShotMethod/SnapShotMethod.h"
#include "MergeMethod/MergeMethod.h"

namespace xstream {
namespace method_factory {
MethodPtr CreateMethod(const std::string &method_name) {
  if ("FasterRCNNMethod" == method_name) {
    return MethodPtr(new FasterRCNNMethod());
  } else if ("MOTMethod" == method_name) {
    return MethodPtr(new MOTMethod());
  } else if ("CNNMethod" == method_name) {
    return MethodPtr(new CNNMethod());
  } else if ("GradingMethod" == method_name) {
    return MethodPtr(new GradingMethod());
  } else if ("SnapShotMethod" == method_name) {
    return MethodPtr(new SnapShotMethod());
  } else if ("MergeMethod" == method_name) {
    return MethodPtr(new MergeMethod());
  } else {
    return MethodPtr();
  }
}
}  // namespace method_factory
}  // namespace xstream