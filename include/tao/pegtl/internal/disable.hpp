// Copyright (c) 2014-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAO_PEGTL_INTERNAL_DISABLE_HPP
#define TAO_PEGTL_INTERNAL_DISABLE_HPP

#include "../config.hpp"

#include "seq.hpp"
#include "skip_control.hpp"

#include "../apply_mode.hpp"
#include "../rewind_mode.hpp"

namespace TAO_PEGTL_NAMESPACE::internal
{
   template< typename... Rules >
   struct disable
      : disable< seq< Rules... > >
   {
      using rule_t = disable;
   };

   template< typename Rule >
   struct disable< Rule >
   {
      using rule_t = disable;
      using analyze_t = analysis::generic< analysis::rule_type::seq, Rule >;

      template< apply_mode,
                rewind_mode M,
                template< typename... >
                class Action,
                template< typename... >
                class Control,
                typename Input,
                typename... States >
      [[nodiscard]] static bool match( Input& in, States&&... st )
      {
         return Control< Rule >::template match< apply_mode::nothing, M, Action, Control >( in, st... );
      }
   };

   template< typename... Rules >
   inline constexpr bool skip_control< disable< Rules... > > = true;

}  // namespace TAO_PEGTL_NAMESPACE::internal

#endif
