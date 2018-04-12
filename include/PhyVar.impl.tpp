template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>::operator+(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar) {
  return PhyVar<NumTypeIn, UnitTypeIn>(this->m_val + otherPhyVar.m_val);
}

template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>&
PhyVar<NumTypeIn, UnitTypeIn>::operator+=(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar) {
  this->m_val += otherPhyVar.m_val;
  return *this;
}


