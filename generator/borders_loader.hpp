#pragma once

#include "geometry/region2d.hpp"
#include "geometry/tree4d.hpp"

#include "std/string.hpp"

#define BORDERS_DIR "borders/"
#define BORDERS_EXTENSION ".poly"

namespace borders
{
  typedef m2::RegionD Region;
  typedef m4::Tree<Region> RegionsContainerT;

  struct CountryPolygons
  {
    CountryPolygons(string const & name = "") : m_name(name), m_index(-1) {}

    bool IsEmpty() const { return m_regions.IsEmpty(); }
    void Clear()
    {
      m_regions.Clear();
      m_name.clear();
      m_index = -1;
    }

    RegionsContainerT m_regions;
    string m_name;
    mutable int m_index;
  };

  typedef m4::Tree<CountryPolygons> CountriesContainerT;

  bool LoadCountriesList(string const & baseDir, CountriesContainerT & countries);

  void GeneratePackedBorders(string const & baseDir);
  void UnpackBorders(string const & baseDir, string const & targetDir);
}
