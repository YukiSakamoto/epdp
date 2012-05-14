#ifndef BINDING_WORLD_HPP
#define BINDING_WORLD_HPP

#include <set>
#include <boost/python.hpp>
#include <boost/range/size_type.hpp>
#include <boost/range/value_type.hpp>
#include <boost/range/const_iterator.hpp>

#include "peer/utils.hpp"
#include "peer/compat.h"
#include "peer/set_indexing_suite.hpp"
#include "peer/converters/tuple.hpp"
#include "utils/range.hpp"
#include "utils/pair.hpp"

namespace binding {

template<typename Timpl_>
struct species_range_converter: public boost::python::default_call_policies
{
    typedef Timpl_ native_type;

    template<typename T_>
    struct policy
    {
        typedef typename boost::range_size<T_>::type size_type;
        typedef typename boost::range_value<T_>::type value_type;
        typedef value_type const& reference;
        typedef value_type const& const_reference;
        typedef typename boost::range_const_iterator<T_>::type iterator;
        typedef typename boost::range_const_iterator<T_>::type const_iterator;

        static size_type size(T_ const& c)
        {
            return ::size(c);
        }

        static void set(T_& c, size_type i, const_reference v)
        {
            PyErr_SetString(PyExc_TypeError, "object does not support indexing");
            boost::python::throw_error_already_set();
        }

        static reference get(T_ const& c, size_type i)
        {
            PyErr_SetString(PyExc_TypeError, "object does not support indexing");
            boost::python::throw_error_already_set();
            throw 0;
        }

        static iterator begin(T_ const& c)
        {
            return boost::begin(c);
        }

        static iterator end(T_ const& c)
        {
            return boost::end(c);
        }
    };

    struct instance_holder
    {
        instance_holder(native_type const& instance,
                        boost::python::handle<> owner)
            : instance_(instance), owner_(owner) {}

        native_type const& operator*() const
        {
            return instance_;
        }

        native_type const* operator->() const
        {
            return &(**this);
        }

        native_type& operator*()
        {
            PyErr_SetString(PyExc_RuntimeError, "object is immutable");
            boost::python::throw_error_already_set();
            return *static_cast<native_type*>(0);
        }

        native_type* operator->()
        {
            return &(**this);
        }

        native_type instance_;
        boost::python::handle<> owner_;
    };

    typedef peer::wrappers::stl_container_wrapper<native_type, instance_holder, peer::wrappers::default_policy_generator<policy> > wrapper_type;

    struct result_converter
    {
        template<typename T_>
        struct apply
        {
            struct type {
                PyObject* operator()(native_type const& val) const
                {
                    return wrapper_type::create(instance_holder(val, boost::python::handle<>()));
                }

                PyTypeObject const* get_pytype() const
                {
                    return &wrapper_type::__class__;
                }
            };
        };
    };

    template<typename Targs>
    static PyObject* postcall(Targs const& arg, PyObject* result)
    {
        reinterpret_cast<wrapper_type*>(result)->ptr().owner_ = boost::python::handle<>(boost::python::borrowed(PyTuple_GET_ITEM(arg, 0)));
        return result;
    }

    static void __register()
    {
        wrapper_type::__class_init__("SpeciesRange", boost::python::scope().ptr());
    }
};

template<typename Timpl_>
struct structures_range_converter: public boost::python::default_call_policies
{
    typedef Timpl_ native_type;

    template<typename T_>
    struct policy
    {
        typedef typename boost::range_size<T_>::type size_type;
        typedef typename boost::range_value<T_>::type value_type;
        typedef value_type const& reference;
        typedef value_type const& const_reference;
        typedef typename boost::range_const_iterator<T_>::type iterator;
        typedef typename boost::range_const_iterator<T_>::type const_iterator;

        static size_type size(T_ const& c)
        {
            return ::size(c);
        }

        static void set(T_& c, size_type i, const_reference v)
        {
            PyErr_SetString(PyExc_TypeError, "object does not support indexing");
            boost::python::throw_error_already_set();
        }

        static reference get(T_ const& c, size_type i)
        {
            PyErr_SetString(PyExc_TypeError, "object does not support indexing");
            boost::python::throw_error_already_set();
            throw 0;
        }

        static iterator begin(T_ const& c)
        {
            return boost::begin(c);
        }

        static iterator end(T_ const& c)
        {
            return boost::end(c);
        }
    };

    struct instance_holder
    {
        instance_holder(native_type const& instance,
                        boost::python::handle<> owner)
            : instance_(instance), owner_(owner) {}

        native_type const& operator*() const
        {
            return instance_;
        }

        native_type const* operator->() const
        {
            return &(**this);
        }

        native_type& operator*()
        {
            PyErr_SetString(PyExc_RuntimeError, "object is immutable");
            boost::python::throw_error_already_set();
            return *static_cast<native_type*>(0);
        }

        native_type* operator->()
        {
            return &(**this);
        }

        native_type instance_;
        boost::python::handle<> owner_;
    };

    typedef peer::wrappers::stl_container_wrapper<native_type, instance_holder, peer::wrappers::default_policy_generator<policy> > wrapper_type;

    struct result_converter
    {
        template<typename T_>
        struct apply
        {
            struct type {
                PyObject* operator()(native_type const& val) const
                {
                    return wrapper_type::create(instance_holder(val, boost::python::handle<>()));
                }

                PyTypeObject const* get_pytype() const
                {
                    return &wrapper_type::__class__;
                }
            };
        };
    };

    template<typename Targs>
    static PyObject* postcall(Targs const& arg, PyObject* result)
    {
        reinterpret_cast<wrapper_type*>(result)->ptr().owner_ = boost::python::handle<>(boost::python::borrowed(PyTuple_GET_ITEM(arg, 0)));
        return result;
    }

    static void __register()
    {
        wrapper_type::__class_init__("StructureRange", boost::python::scope().ptr());
    }
};


template<typename Timpl_>
struct structure_id_pair_and_distance_list_converter
{
    typedef Timpl_ native_type;

    struct to_python_converter
    {
        template<typename T_>
        struct policy
        {
            typedef typename boost::range_size<T_>::type size_type;
            typedef typename boost::range_value<T_>::type value_type;
            typedef value_type const& reference;
            typedef value_type const& const_reference;
            typedef typename boost::range_const_iterator<T_>::type iterator;
            typedef typename boost::range_const_iterator<T_>::type const_iterator;

            static size_type size(T_ const& c)
            {
                return ::size(c);
            }

            static void set(T_& c, size_type i, const_reference v)
            {
                c.set(i, v);
            }

            static reference get(T_ const& c, size_type i)
            {
                return c.at(i);
            }

            static iterator begin(T_ const& c)
            {
                return boost::begin(c);
            }

            static iterator end(T_ const& c)
            {
                return boost::end(c);
            }
        };

        typedef peer::wrappers::stl_container_wrapper<native_type, std::auto_ptr<native_type>, peer::wrappers::default_policy_generator<policy> > wrapper_type;
        static PyObject* convert(native_type* v)
        {
            return reinterpret_cast<PyObject*>(wrapper_type::create(std::auto_ptr<native_type>(v ? v: new native_type())));
        }
    };

    struct to_native_converter
    {
        static PyTypeObject const* expected_pytype()
        {
            return &PyBaseObject_Type;
        }

        static void* convert(PyObject* pyo)
        {
            if (pyo == Py_None)
            {
                return 0;
            }

            Py_ssize_t hint(-1);
            hint = PyObject_Size(pyo);
            if (hint < 0)
            {
                PyErr_Clear();
            }

            boost::python::handle<> iter(PyObject_GetIter(pyo));
            if (!iter)
            {
                boost::python::throw_error_already_set();
            }

            if (hint < 0)
            {
                hint = compat_PyObject_LengthHint(iter.get());
                if (hint < 0)
                {
                    hint = 0;
                }
            }

            native_type* obj(new native_type);
            obj->reserve(hint);
            while (PyObject* item = PyIter_Next(iter.get()))
            {
                obj->push_back(boost::python::extract<typename native_type::value_type>(item)());
            }

            return obj;
        }
    };

    static void __register()
    {
        to_python_converter::wrapper_type::__class_init__("StructureIDAndDistanceVector", boost::python::scope().ptr());
        boost::python::to_python_converter<native_type*, to_python_converter>();
        peer::util::to_native_lvalue_converter<native_type, to_native_converter>();
    }
};

template<typename T>
static typename get_select_first_range<typename T::particle_id_pair_range>::type
World_get_particle_ids(T const& world)
{
    return make_select_first_range(world.get_particles_range());
}

template<typename Timpl_, typename Tbase_, typename Tsim>
inline boost::python::objects::class_base register_world_class(char const* name)
{
    using namespace boost::python;
    typedef Timpl_ impl_type;
    typedef species_range_converter<typename impl_type::species_range> species_range_converter_type;
    typedef structures_range_converter<typename impl_type::structures_range> structures_range_converter_type;

    peer::converters::register_tuple_converter<typename impl_type::structure_id_pair>();
    peer::converters::register_tuple_converter<typename std::pair<typename impl_type::structure_id_type, typename impl_type::length_type> >();
    structure_id_pair_and_distance_list_converter<typename impl_type::structure_id_pair_and_distance_list>::__register();
    species_range_converter_type::__register();
    structures_range_converter_type::__register();

    class_<std::set<typename impl_type::particle_id_type> >("ParticleIDSet")
        .def(peer::util::set_indexing_suite<std::set<typename impl_type::particle_id_type> >())
        ;

    class_<std::set<typename impl_type::structure_id_type> >("StructureIDSet")
        .def(peer::util::set_indexing_suite<std::set<typename impl_type::structure_id_type> >())
        ;

    return class_<impl_type, bases<Tbase_>,
                  boost::shared_ptr<impl_type> >(
        "World", init<typename impl_type::length_type, typename impl_type::size_type>())
        .add_property("cell_size", &impl_type::cell_size)
        .add_property("matrix_size", &impl_type::matrix_size)
        .add_property("species",
            make_function(
                (typename impl_type::species_range(impl_type::*)() const)&impl_type::get_species, species_range_converter_type()))
        .add_property("structures",
            make_function(
                (typename impl_type::structures_range(impl_type::*)() const)&impl_type::get_structures, structures_range_converter_type()))
        .add_property("particle_ids", &World_get_particle_ids<impl_type>)
        .def("add_species", &impl_type::add_species)
        .def("add_structure", &impl_type::add_structure)
        .def("get_structure_ids", &impl_type::get_structure_ids)
        .def("get_particle_ids", &impl_type::get_particle_ids)
        .def("get_closest_structure", &impl_type::get_closest_structure)
        .def("distance", &impl_type::template distance<typename impl_type::position_type>)
        .def("distance", &impl_type::template distance<typename Tsim::sphere_type>)
        .def("distance", &impl_type::template distance<typename Tsim::cylinder_type>)
        .def("distance", &impl_type::template distance<typename Tsim::box_type>)
        .def("distance", &impl_type::template distance<typename Tsim::plane_type>)
        .def("calculate_pair_CoM", &impl_type::template calculate_pair_CoM<typename impl_type::position_type>)
        ;
}

} // namespace binding

#endif /* BINDING_WORLD_HPP */
