#pragma once

#include "Node.h"

namespace nTiled {
namespace pipeline {
namespace hashed {
namespace slt {

class No: public Node {
public:
  No();
  virtual ~No() override;

  virtual void addToLightOctreeNode(lo::Node* node, 
                                    const SingleLightTree& slt) const override;

  virtual void exportToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer) const override;
  virtual void exportToJson(rapidjson::Writer<rapidjson::StringBuffer>& writer, glm::uvec3 position) const;
};

}
}
}
}