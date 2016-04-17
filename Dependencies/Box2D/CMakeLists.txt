cmake_minimum_required(VERSION 2.8)

project(Box2D)

add_library(Box2D STATIC
							src/Collision/b2BroadPhase.cpp
							src/Collision/b2CollideCircle.cpp
							src/Collision/b2CollideEdge.cpp
							src/Collision/b2CollidePolygon.cpp
							src/Collision/b2Collision.cpp
							src/Collision/b2Distance.cpp
							src/Collision/b2DynamicTree.cpp
							src/Collision/b2TimeOfImpact.cpp
							src/Collision/Shapes/b2ChainShape.cpp
							src/Collision/Shapes/b2CircleShape.cpp
							src/Collision/Shapes/b2EdgeShape.cpp
							src/Collision/Shapes/b2PolygonShape.cpp
							src/Common/b2BlockAllocator.cpp
							src/Common/b2Draw.cpp
							src/Common/b2Math.cpp
							src/Common/b2Settings.cpp
							src/Common/b2StackAllocator.cpp
							src/Common/b2Timer.cpp
							src/Dynamics/b2Body.cpp
							src/Dynamics/b2ContactManager.cpp
							src/Dynamics/b2Fixture.cpp
							src/Dynamics/b2Island.cpp
							src/Dynamics/b2World.cpp
							src/Dynamics/b2WorldCallbacks.cpp
							src/Dynamics/Contacts/b2ChainAndCircleContact.cpp
							src/Dynamics/Contacts/b2ChainAndPolygonContact.cpp
							src/Dynamics/Contacts/b2CircleContact.cpp
							src/Dynamics/Contacts/b2Contact.cpp
							src/Dynamics/Contacts/b2ContactSolver.cpp
							src/Dynamics/Contacts/b2EdgeAndCircleContact.cpp
							src/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp
							src/Dynamics/Contacts/b2PolygonAndCircleContact.cpp
							src/Dynamics/Contacts/b2PolygonContact.cpp
							src/Dynamics/Joints/b2DistanceJoint.cpp
							src/Dynamics/Joints/b2FrictionJoint.cpp
							src/Dynamics/Joints/b2GearJoint.cpp
							src/Dynamics/Joints/b2Joint.cpp
							src/Dynamics/Joints/b2MotorJoint.cpp
							src/Dynamics/Joints/b2MouseJoint.cpp
							src/Dynamics/Joints/b2PrismaticJoint.cpp
							src/Dynamics/Joints/b2PulleyJoint.cpp
							src/Dynamics/Joints/b2RevoluteJoint.cpp
							src/Dynamics/Joints/b2RopeJoint.cpp
							src/Dynamics/Joints/b2WeldJoint.cpp
							src/Dynamics/Joints/b2WheelJoint.cpp
							src/Rope/b2Rope.cpp)

include_directories(src)
set_target_properties(Box2D PROPERTIES PREFIX "")

