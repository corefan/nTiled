#pragma once

// ---------------------------------------------------------------------------
//  Libraries
// ---------------------------------------------------------------------------
#include <vector>
#include <glm\glm.hpp>

// ---------------------------------------------------------------------------
//  nTiled Headers 
// ---------------------------------------------------------------------------
#include "Table.h"


namespace nTiled {
namespace pipeline {
namespace hashed {

/*! @brief SpatialHashFunction<R> describes a single 3d hash function holding 
 *         data of type R. This implementation is based on the paper
 *         Perfect Spatial Hashing.
 * 
 *  The hash function is build with both a hashtable H and an offset table
 *  Phi. Hash table H contains data of type R, while the offset table is
 *  defined as elements of glm::u8vec3.
 * 
 *  The spatial Hash function is defined as:
 *    h(p) = h_0(p) + Phi(h_1(p))
 */
template <class R>
class SpatialHashFunction {
public:

  // --------------------------------------------------------------------------
  //  Constructor | Destructor
  /*! @brief Construct a new SpatialHashFunction with the given hash table H 
   *         and offset table Phi
   *
   */
  SpatialHashFunction(Table<R>* p_hash_table,
                      Table<glm::u8vec3>* p_offset_table);

  /*! @brief Destruct this SpatialHashFunction
   */
  ~SpatialHashFunction();

  // --------------------------------------------------------------------------
  //  Getters

  /*! @brief Get the hash table of this SpatialHashFunction
   *  
   * @return The hash table of this SpatialHashFunction
   */
  const std::vector<R>& getHashTable() const { return this->p_hash_table->getDataVector(); }

  /*! @brief Get the offset table of this sPatialHashfunction
   *
   * @return The offset table of this SpatialHashFunction
   */
  const std::vector<glm::u8vec3>& getOffsetTable() const { return this->p_offset_table->getDataVector(); }

  /*! @brief Get the data associated with point p from within this Spatial Hash Function
   * 
   * @param p The point of which the associated data should be returned.
   *
   * @return The data associated with point p
   */
  R getData(glm::uvec3 p) const;

  /*! @Brief Get the size m in one dimension of this SpatialHashFunction's 
   *         HashTable
   *
   * @return The size m in one dimension of this SpatialHashFunction's HashTable
   */
  inline unsigned int getM() const { return this->p_hash_table->getDim(); }

  /*! @brief Get the size r in one dimension of this SpatialHashFunction's 
   *         offset table
   *
   * @return The size r in one dimension of this SpatialHashFunction's
   *         offset table.
   */
  inline unsigned int getR() const { return this->p_offset_table->getDim(); }

private:
  /*! @brief Pointer to the hash table of this SpatialHashFunction. */
  Table<R>* p_hash_table;

  /*! @brief Pointer to the offset table of this SpatialHashFunction. */
  Table<glm::u8vec3>* p_offset_table;
};

}
}
}
