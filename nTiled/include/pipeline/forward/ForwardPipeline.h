#pragma once

// ----------------------------------------------------------------------------
//  nTiled headers
// ----------------------------------------------------------------------------
#include "pipeline\Pipeline.h"
#include "pipeline\forward\shaders\ForwardShader.h"


namespace nTiled {
namespace pipeline {

class ForwardPipeline : public Pipeline {
public:
  ForwardPipeline(state::State& state);
  ~ForwardPipeline();

  // Render Methods
  virtual void render() override;
private:
  std::vector<ForwardShader*> shader_catalog;
};

} // pipeline
} // nTiled
