namespace PhyV {

template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>::operator*(const NumTypeIn& scal) const {
   PhyVar<NumTypeIn, UnitTypeIn> res(this->m_val);
  res *= scal;
  return res;
}

template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>::operator+(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar) const {
  PhyVar<NumTypeIn, UnitTypeIn> res(this->m_val);
  res += otherPhyVar;
  return res;
}


template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>::operator-(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar) const {
  PhyVar<NumTypeIn, UnitTypeIn> res(this->m_val);
  res -= otherPhyVar;
  return res;
}

template <typename NumTypeIn, typename UnitTypeIn>
template <typename UnitTypeOther>
PhyVar<NumTypeIn,
       Unit <UnitTypeIn::kg + UnitTypeOther::kg,
             UnitTypeIn::m  + UnitTypeOther::m,
             UnitTypeIn::s  + UnitTypeOther::s> >
PhyVar<NumTypeIn, UnitTypeIn>::operator*(const PhyVar<NumTypeIn, UnitTypeOther>& otherPhyVar) const {
  return PhyVar<NumTypeIn,
       Unit <UnitTypeIn::kg + UnitTypeOther::kg,
             UnitTypeIn::m  + UnitTypeOther::m,
             UnitTypeIn::s  + UnitTypeOther::s> >(this->m_val * otherPhyVar.m_val);
}


template <typename NumTypeIn, typename UnitTypeIn>
template <typename UnitTypeOther>
PhyVar<NumTypeIn,
       Unit <UnitTypeIn::kg - UnitTypeOther::kg,
             UnitTypeIn::m  - UnitTypeOther::m,
             UnitTypeIn::s  - UnitTypeOther::s> >
PhyVar<NumTypeIn, UnitTypeIn>::operator/(const PhyVar<NumTypeIn, UnitTypeOther>& otherPhyVar) const {
  return PhyVar<NumTypeIn,
       Unit <UnitTypeIn::kg - UnitTypeOther::kg,
             UnitTypeIn::m  - UnitTypeOther::m,
             UnitTypeIn::s  - UnitTypeOther::s> >(this->m_val / otherPhyVar.m_val);
}



template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>&
PhyVar<NumTypeIn, UnitTypeIn>::operator*=(const NumTypeIn& scal) {
  this->m_val *= scal;
  return *this;
}


template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>&
PhyVar<NumTypeIn, UnitTypeIn>::operator+=(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar) {
  this->m_val += otherPhyVar.m_val;
  return *this;
}


template <typename NumTypeIn, typename UnitTypeIn>
PhyVar<NumTypeIn, UnitTypeIn>&
PhyVar<NumTypeIn, UnitTypeIn>::operator-=(const PhyVar<NumTypeIn, UnitTypeIn>& otherPhyVar) {
  this->m_val -= otherPhyVar.m_val;
  return *this;
}


} // namespace PhyV
