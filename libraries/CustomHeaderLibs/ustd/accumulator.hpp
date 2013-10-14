// Author:  Mario S. Könz <mskoenz@gmx.net>
// Date:    20.07.2013 11:27:21 EDT
// File:    accumulator.hpp

#ifndef __ACCUMULATOR_HEADER
#define __ACCUMULATOR_HEADER

#include "accumulator/tags.hpp"
#include "accumulator/ema_module.hpp"
#include "accumulator/max_module.hpp"
#include "accumulator/min_module.hpp"
#include "accumulator/mean_module.hpp"
#include "accumulator/error_module.hpp"
#include "accumulator/count_module.hpp"


namespace ustd {
    namespace detail {
        template<typename item, typename next_item>
        struct add_dependecies_rec {
            typedef typename concatinate_lists<typename requirement<item>::type
                                             , typename concatinate_lists< list_item<item, list_end>
                                                                , typename add_dependecies_rec<typename next_item::type
                                                                                            , typename next_item::next>::type
                                                                         >::type
                                              >::type
                                         type;
        };
        template<typename item>
        struct add_dependecies_rec<item, list_end> {
            typedef 
                typename concatinate_lists<typename requirement<item>::type
                                             , list_item<item, list_end>
                                             >::type 
            type;
        };
        template<typename list>
        struct add_dependecies {
            typedef typename add_dependecies_rec<typename list::type, typename list::next>::type type;
        };
    }//end namespace detail
    
    template<typename T, typename list>
    struct accumulator_deriver: accumulator_deriver<T, typename list::next>::type {
        typedef 
            module<T
                , typename list::type
                , typename accumulator_deriver<T
                    , typename list::next
                    >::type
            > 
        type;
    };
    
    template<typename T>
    struct accumulator_deriver<T, list_end> {
        typedef accumulator_base<T> type;
    };
    
    template< typename T = double
            , typename T0 = tag::error
            , typename T1 = void
            , typename T2 = void
            , typename T3 = void
            , typename T4 = void
            , typename T5 = void
            , typename T6 = void
            , typename T7 = void
            , typename T8 = void
            , typename T9 = void
            >
    class accumulator: public accumulator_deriver<  T
                                                  , typename invert_list<
                                                        typename unique_list<
                                                            typename detail::add_dependecies<
                                                                typename make_list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::type
                                                            >::type 
                                                        >::type 
                                                    >::type 
                                                 >::type {
    };
}//end namespace ustd 
#endif //__ACCUMULATOR_HEADER
