#ifndef ADDENTRY_HPP
#define ADDENTRY_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

namespace dto {

    class AddEntryReqDto : public oatpp::DTO {

        DTO_INIT( AddEntryReqDto, DTO )

        DTO_FIELD( String, key );
        DTO_FIELD( String, value );

    };

    class AddEntryResDto : public oatpp::DTO {

        DTO_INIT( AddEntryResDto, DTO )

        DTO_FIELD( Int16, statusCode ); // status about whether new entry added, old updated, error

    };

}

#include OATPP_CODEGEN_END(DTO)

#endif //!ADDENTRY_HPP
