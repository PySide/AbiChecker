/*
 * This file is part of the Shiboken Python Bindings Generator project.
 *
 * Copyright (C) 2009-2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: PySide team <contact@pyside.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef SBK_HELPER_H
#define SBK_HELPER_H

#include <shibokenmacros.h>
#include <conversions.h>
#include <autodecref.h>

#include <Python.h>

namespace Shiboken
{

template<typename A>
inline PyObject* makeTuple(const A& a)
{
    return PyTuple_Pack(1, AutoDecRef(Converter<A>::toPython(a)).object());
}

template<typename A, typename B>
inline PyObject* makeTuple(const A& a, const B& b)
{
    return PyTuple_Pack(2, AutoDecRef(Converter<A>::toPython(a)).object(),
                           AutoDecRef(Converter<B>::toPython(b)).object());
}

template<typename A, typename B, typename C>
inline PyObject* makeTuple(const A& a, const B& b, const C& c)
{
    return PyTuple_Pack(3, AutoDecRef(Converter<A>::toPython(a)).object(),
                           AutoDecRef(Converter<B>::toPython(b)).object(),
                           AutoDecRef(Converter<C>::toPython(c)).object());
}

template<typename A, typename B, typename C, typename D>
inline PyObject* makeTuple(const A& a, const B& b, const C& c, const D& d)
{
    return PyTuple_Pack(4, AutoDecRef(Converter<A>::toPython(a)).object(),
                           AutoDecRef(Converter<B>::toPython(b)).object(),
                           AutoDecRef(Converter<C>::toPython(c)).object(),
                           AutoDecRef(Converter<D>::toPython(d)).object());
}

template<typename A, typename B, typename C, typename D, typename E>
inline PyObject* makeTuple(const A& a, const B& b, const C& c, const D& d, const E& e)
{
    return PyTuple_Pack(5, AutoDecRef(Converter<A>::toPython(a)).object(),
                           AutoDecRef(Converter<B>::toPython(b)).object(),
                           AutoDecRef(Converter<C>::toPython(c)).object(),
                           AutoDecRef(Converter<D>::toPython(d)).object(),
                           AutoDecRef(Converter<E>::toPython(e)).object());
}

/**
* It transforms a python sequence into two C variables, argc and argv.
* This function tries to find the application (script) name and put it into argv[0], if
* the application name can't be guessed, defaultAppName will be used.
*
* No memory is allocated is an error occur.
*
* \note argc must be a valid address.
* \note The argv array is allocated using new operator and each item is allocated using malloc.
* \returns True on sucess, false otherwise.
*/
LIBSHIBOKEN_API bool sequenceToArgcArgv(PyObject* argList, int* argc, char*** argv, const char* defaultAppName = 0);

/**
 * Convert a python sequence into a heap-allocated array of ints.
 *
 * \returns The newly allocated array or NULL in case of error or empty sequence. Check with PyErr_Occurred
 *          if it was successfull.
 */
LIBSHIBOKEN_API int* sequenceToIntArray(PyObject* obj, bool zeroTerminated = false);

} // namespace Shiboken

#endif // SBK_HELPER_H

