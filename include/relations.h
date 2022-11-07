/**
 * @file relations.h
 * @author Jose Ruiz Alarcon
 * @brief  Module that defines the functions implemented by relations.c
 */

#ifndef _QBAF_RELATIONS_H_
#define _QBAF_RELATIONS_H_

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "qbaf_module.h"

/**
 * @brief Get the QBAFARelationsType object that defines the class QBAFARelations
 * 
 * @return PyTypeObject* a pointer to the QBAFARelations class definition
 */
// PyTypeObject *get_QBAFARelationsType(void);

/**
 * @brief Struct that defines the Object Type ARelations in a QBAF.
 * 
 */
typedef struct {
    PyObject_HEAD
    PyObject *relations;        /* set of tuples (Agent: QBAFArgument, Patient: QBAFArgument) */
    PyObject *agent_patients;   /* dictonary of (key, value) = (Agent, set of Patients) */
    PyObject *patient_agents;   /* dictonary of (key, value) = (Patient, set of Agents) */
} QBAFARelationsObject;

/**
 * @brief Create a new object QBAFARelations.
 * 
 * @param relations a set/list of tuples (Agent: QBAFArgument, Patient QBAFArgument)
 * @return PyObject* New reference
 */
PyObject *QBAFARelations_Create(PyObject *relations);

/**
 * @brief Return 1 if their relations are disjoint, 0 if they are not, and -1 if an error is encountered.
 * 
 * @param self a QBAFARelations instance (not NULL)
 * @param other a different QBAFARelations instance (not NULL)
 * @return int 1 if they are disjoint, 0 if they are not, and -1 if an error is encountered
 */
int _QBAFARelations_isDisjoint(QBAFARelationsObject *self, QBAFARelationsObject *other);

#endif