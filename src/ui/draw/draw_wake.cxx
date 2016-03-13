/*
 * Quadrotor's FVM result drawing
 *          using OpenGL GLUT
 *
 * This file contains stuff to draw the wake of a quadrotor
 * using OpenGL GLUT.
 * The declarations of the classes or functions are written in 
 * file draw_wake.h, which is included by DrawScene.h
 *
 * Author: Roice (LUO Bing)
 * Date: 2016-03-07 create this file
 */
#include <FL/gl.h>
#include <vector>
#include "model/robot.h"
#include <stdio.h>


/* draw a vortex filament */
static void draw_vortex_filament(const std::vector<VortexMarker_t>* markers)
{
    int n_m = markers->size();

    // draw
    glDisable(GL_LIGHTING);

    glColor3f(0.0, 1.0, 0.0); /* green */
    glBegin(GL_LINES);
    for (int i = 0; i < n_m-1; i++)
    {// draw each segment as line segment    
  	    glVertex3f(markers->at(i).pos[0],
                markers->at(i).pos[2], 
                markers->at(i).pos[1]);
        glVertex3f(markers->at(i+1).pos[0],
                markers->at(i+1).pos[2], 
                markers->at(i+1).pos[1]);
    }
    glEnd();
    
    glEnable(GL_LIGHTING);
}

/* draw the wake generated by quad rotor */
void draw_wake(std::vector<Robot*>* robots)
{
    /* draw FVM vortex filaments */
    draw_vortex_filament(robots->at(0)->wakes.at(0)->wake_state[0]);
}
