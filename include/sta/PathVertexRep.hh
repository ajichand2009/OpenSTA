// OpenSTA, Static Timing Analyzer
// Copyright (c) 2025, Parallax Software, Inc.
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
// 
// The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software.
// 
// Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
// 
// This notice may not be removed or altered from any source distribution.

#pragma once

#include "SdcClass.hh"
#include "SearchClass.hh"

namespace sta {

// Path representation that references a vertex arrival via a tag.
// This does not implement the Path API which uses virtual functions
// that would make it larger.
class PathVertexRep
{
public:
  explicit PathVertexRep();
  explicit PathVertexRep(const PathVertexRep *path);
  PathVertexRep(const PathVertexRep &path);
  explicit PathVertexRep(const PathVertex *path,
			 const StaState *sta);
  explicit PathVertexRep(const PathVertex &path,
			 const StaState *sta);
  explicit PathVertexRep(VertexId vertex_id,
			 TagIndex tag_index,
			 bool is_enum);
  void init();
  void init(const PathVertexRep *path);
  void init(const PathVertexRep &path);
  void init(const PathVertex *path,
	    const StaState *sta);
  void init(const PathVertex &path,
	    const StaState *sta);
  bool isNull() const { return vertex_id_ == 0; }
  Vertex *vertex(const StaState *) const;
  VertexId vertexId() const { return vertex_id_; }
  Tag *tag(const StaState *sta) const;
  TagIndex tagIndex() const { return tag_index_; }
  Arrival arrival(const StaState *sta) const;
  void prevPath(const StaState *sta,
		// Return values.
		PathRef &prev_path,
		TimingArc *&prev_arc) const;

  static bool equal(const PathVertexRep *path1,
		    const PathVertexRep *path2);
  static bool equal(const PathVertexRep &path1,
		    const PathVertexRep &path2);
  static int cmp(const PathVertexRep *path1,
		 const PathVertexRep *path2);
  static int cmp(const PathVertexRep &path1,
		 const PathVertexRep &path2);

protected:
  VertexId vertex_id_;
  TagIndex tag_index_;
  bool is_enum_:1;
};

} // namespace
