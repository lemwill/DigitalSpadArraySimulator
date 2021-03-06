/* FILE_INFO_START
 * Copyright (C) 2016 
 * 
 * ***********************************************************************
 * This file is part of SpadSimulator
 * 
 * SpadSimulator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * SpadSimulator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SpadSimulator.  If not, see <http://www.gnu.org/licenses/>.
 * ***********************************************************************
 * 
 * File        : laser_event_importer.cc
 * Author      : Audrey Corbeil Therrien <audrey.corbeil.therrien@usherbrooke.ca>
 * Author      : Valentin Libioulle <valentin.libioulle@usherbrooke.ca>
 * Created     : Wed Apr 13 14:09:34 2016 -0400 by valentin
 * 
 * FILE_INFO_END */


#include "laser_event_importer.hh"

#include "isensor_matrix.hh"
#include "photon.hh"
#include "position.hh"
#include "random.hh"
#include "vector.hh"

LaserEventImporter::LaserEventImporter(const int& photonsPerEvent, const double& wavelength)
: EventImporter()
, photonsPerEvent(photonsPerEvent)
, wavelength(wavelength)
{}

LaserEventImporter::~LaserEventImporter()
{}

void LaserEventImporter::importSingleEvent(const int&, 
                                           const ISensorMatrix& matrix, 
                                           const double& timeDelay, 
                                           Vector< Photon* >& photons)
{
    photons.clearAndDelete();
    Position2D matrixDimension = matrix.getDimension();
    Position3D postMomentum = Position3D(1, 1, 1);
    Position2D randomPosition;
    
    for (int i = 0; i < photonsPerEvent; ++i) {
        randomPosition.x = RandomGenerator::rand() * matrixDimension.x;
        randomPosition.y = RandomGenerator::rand() * matrixDimension.y;
        photons.push_back(new Photon(timeDelay, randomPosition, postMomentum, wavelength));
    }
}
