// Copyright (c) 2016-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAO_PEGTL_INTERNAL_DISCARD_HPP
#define TAO_PEGTL_INTERNAL_DISCARD_HPP

#include "../config.hpp"

#include "skip_control.hpp"

namespace TAO_PEGTL_NAMESPACE::internal
{
   struct discard
   {
      using rule_t = discard;
      using analyze_t = analysis::generic< analysis::rule_type::opt >;

      template< typename Input >
      [[nodiscard]] static bool match( Input& in ) noexcept
      {
         static_assert( noexcept( in.discard() ) );
         in.discard();
         return true;
      }
   };

   template<>
   inline constexpr bool skip_control< discard > = true;

}  // namespace TAO_PEGTL_NAMESPACE::internal

#endif
