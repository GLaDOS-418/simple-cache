#ifndef RETRIEVEENTRYDTO_H
#define RETRIEVEENTRYDTO_H

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace dto {

    class RetrieveEntryReqDto : public oatpp::DTO {

        DTO_INIT( RetrieveEntryReqDto, DTO )

        DTO_FIELD( String, key );

    };

    class RetrieveEntryResDto : public oatpp::DTO {

        DTO_INIT( RetrieveEntryResDto, DTO )

        DTO_FIELD( Int16, statusCode );
        DTO_FIELD( String, value );

    };

}

#include OATPP_CODEGEN_END(DTO)

#endif // !RETRIEVEENTRYDTO_H
