/**
 * Copyright (C) 2012 Alec Thomas <alec@swapoff.org>
 * All rights reserved.
 * 
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 * 
 * Author: Alec Thomas <alec@swapoff.org>
 */

#pragma once

#include <boost/timer.hpp>
#include "entityx/Entity.h"
#include "entityx/Event.h"
#include "entityx/System.h"

namespace entity {

class World {
 public:
  World() : entity_manager(event_manager), system_manager(entity_manager, event_manager) {}
  virtual ~World() {}

  void start();
  void run();
  void stop();

 protected:
  /**
   * Configure the world.
   *
   * This is called once on World initialization. It is typically used to add Systems to the world, load permanent
   * resources, global configuration, etc.
   */
  virtual void configure() = 0;

  /**
   * Initialize the entities and events in the world.
   *
   * Typically used when 
   */
  virtual void initialize() = 0;

  /**
   * Update the world.
   */
  virtual void update(double dt) = 0;

  EventManager event_manager;
  EntityManager entity_manager;
  SystemManager system_manager;

 private:
  boost::timer timer_;
  bool running_ = false;
};

}
