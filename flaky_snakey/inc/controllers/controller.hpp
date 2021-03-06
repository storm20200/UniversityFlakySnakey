/*
   Program: Flaky Snakey
   Created by Simon Peter Campbell

   The purpose of Flaky Snakey is simply to show understanding of OOP concepts for my C++ Programming
   module. Using the supplied PRG library I had the task of creating a Snake-like game.

   Copyright (C) 2014 Simon Peter Campbell
   This file is part of Flaky Snakey.

   Flaky Snakey is free software: you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free Software Foundation,
   either version 3 of the License, or any later version. Flaky Snakey is distributed
   in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
   Public License for more details. You should have received a copy of the GNU General Public
   License along with Flaky Snakey. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef CONTROLLER_H
#define CONTROLLER_H


/// STL
#include <memory> // weak_ptr and shared_ptr


/// Personal
#include <misc/movement.hpp>


/// Forward declarations
class Snake;


/// Controller is the base class which all other Snake controllers are derived from. It provides the functionality to move
/// the Snake effectively.
/// Controller is an abstract class.
class Controller
{
   public:
      /// Constructors and destructor
      Controller();

      Controller (Controller&& move) = default;
      Controller (const Controller& copy) = default;
      Controller& operator= (const Controller& copy) = default;
      virtual ~Controller() {}


      /// Assignment functions
      void setSnake (const std::shared_ptr<Snake>& snake);


      /// Getters
      virtual Movement getMove() = 0;

   protected:
      std::weak_ptr<const Snake> m_pkSnake;   /// Provides access to the controlled Snake
      Movement m_lastMove;                   /// Keeps a reference of the previous move generated by the Controller
      Movement m_move;                       /// The current move generated by the Controller

   private:

};

#endif // CONTROLLER_H

/// See <interface/idrawable.hpp> for reasoning behind destructor
