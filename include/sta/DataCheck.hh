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

#include "MinMax.hh"
#include "LibertyClass.hh"
#include "NetworkClass.hh"
#include "NetworkCmp.hh"
#include "SdcClass.hh"
#include "RiseFallMinMax.hh"

namespace sta {

class DataCheck
{
public:
  DataCheck(Pin *from,
	    Pin *to,
	    Clock *clk);
  Pin *from() const { return from_; }
  Pin *to() const { return to_; }
  Clock *clk() const { return clk_; }
  void margin(const RiseFall *from_rf,
	      const RiseFall *to_rf,
	      const SetupHold *setup_hold,
	      // Return values.
	      float &margin,
	      bool &exists) const;
  void setMargin(const RiseFallBoth *from_rf,
		 const RiseFallBoth *to_rf,
		 const SetupHoldAll *setup_hold,
		 float margin);
  void removeMargin(const RiseFallBoth *from_rf,
		    const RiseFallBoth *to_rf,
		    const SetupHoldAll *setup_hold);
  bool empty() const;
  void marginIsOneValue(const SetupHold *setup_hold,
			// Return values.
			float &value,
			bool &one_value) const;

private:
  Pin *from_;
  Pin *to_;
  Clock *clk_;
  RiseFallMinMax margins_[RiseFall::index_count];
};

class DataCheckLess
{
public:
  DataCheckLess(const Network *network);
  bool operator()(const DataCheck *check1,
		  const DataCheck *check2) const;

private:
  const Network *network_;
};

} // namespace
