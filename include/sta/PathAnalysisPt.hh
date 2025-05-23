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

#include <string>

#include "Iterator.hh"
#include "MinMax.hh"
#include "SdcClass.hh"
#include "SearchClass.hh"

namespace sta {

class MinMax;
class DcalcAnalysisPt;
class Corner;

using std::string;

class PathAnalysisPt
{
public:
  PathAnalysisPt(Corner *corner,
		 PathAPIndex index,
		 const MinMax *path_min_max,
		 DcalcAnalysisPt *dcalc_ap);
  string to_string() const;
  Corner *corner() const { return corner_; }
  PathAPIndex index() const { return index_; }
  const MinMax *pathMinMax() const { return path_min_max_; }
  // Converging path arrival merging.
  const MinMax *mergeMinMax() const { return path_min_max_; }
  // Path analysis point for timing check target clock arrivals.
  PathAnalysisPt *tgtClkAnalysisPt() const { return tgt_clk_ap_; }
  void setTgtClkAnalysisPt(PathAnalysisPt *path_ap);
  DcalcAnalysisPt *dcalcAnalysisPt() const { return dcalc_ap_; }
  PathAnalysisPt *insertionAnalysisPt(const EarlyLate *early_late) const;
  void setInsertionAnalysisPt(const EarlyLate *early_late, PathAnalysisPt *ap);

private:
  Corner *corner_;
  PathAPIndex index_;
  const MinMax *path_min_max_;
  PathAnalysisPt *tgt_clk_ap_;
  PathAnalysisPt *insertion_aps_[EarlyLate::index_count];
  DcalcAnalysisPt *dcalc_ap_;
};

} // namespace
