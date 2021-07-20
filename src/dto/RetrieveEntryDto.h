#ifndef RETRIEVEENTRYDTO_H
#define RETRIEVEENTRYDTO_H

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace dto {
    /**
     *  Data Transfer Object. Object containing fields only.
     *  Used in API for serialization/deserialization and validation
     */
    class RetrieveEntry : public oatpp::DTO {

        DTO_INIT( RetrieveEntry, DTO )

        DTO_FIELD( Int16, statusCode );
        DTO_FIELD( String, value );

    };

}

#include OATPP_CODEGEN_END(DTO)

#endif // !RETRIEVEENTRYDTO_H
