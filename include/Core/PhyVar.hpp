#ifndef PHYVAR_HPP
#define PHYVAR_HPP

#include "PhyVar.tpp"

namespace PhyV {
// Base unit

typedef Unit<  0,  0,  0> NoUnit;

typedef Unit<  0,  1,  0> Distance;
typedef Unit<  0,  1,  0> Position;
typedef Unit<  0,  1, -1> Velocity;
typedef Unit<  0,  1, -2> Acceleration;

typedef Unit<  0,  0,  1> Time;

typedef Unit<  1,  0,  0> Mass;

typedef Unit<  1,  1, -2> Newton;


// Float var

typedef PhyVar<float, NoUnit>       NoUnitF;

typedef PhyVar<float, Distance>     DistanceF;
typedef PhyVar<float, Position>     PositionF;
typedef PhyVar<float, Velocity>     VelocityF;
typedef PhyVar<float, Acceleration> AccelerationF;

typedef PhyVar<float, Time>         TimeF;

typedef PhyVar<float, Mass>         MassF;

typedef PhyVar<float, Newton>       NewtonF;


// Double var


typedef PhyVar<double, NoUnit>       NoUnitD;

typedef PhyVar<double, Distance>     DistanceD;
typedef PhyVar<double, Position>     PositionD;
typedef PhyVar<double, Velocity>     VelocityD;
typedef PhyVar<double, Acceleration> AccelerationD;

typedef PhyVar<double, Time>         TimeD;

typedef PhyVar<double, Mass>         MassD;

typedef PhyVar<double, Newton>       NewtonD;

} // namespace PhyV

#endif // PHYVAR_HPP
