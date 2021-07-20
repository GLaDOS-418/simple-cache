#ifndef ADDENTRY_HPP
#define ADDENTRY_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace dto {
    /**
     *  Data Transfer Object. Object containing fields only.
     *  Used in API for serialization/deserialization and validation
     */
    class AddEntryDto : public oatpp::DTO {

        DTO_INIT( AddEntryDto, DTO )

        DTO_FIELD( String, key );
        DTO_FIELD( String, value );

    };

}

#include OATPP_CODEGEN_END(DTO)

#endif /* DTOs_hpp */
