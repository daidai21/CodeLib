include "./included.thrift"


namespace java com.example.project
namespace cpp com.example.project
namespace py com.example.project
namespace go com.example.project


typedef i64 Long

const string APP_NAME = "demo"
const map<string, i64> BIZ_MAP = {
    "demo1": 123,
    "demo2": 456
}

struct BaseTypeExample {
    1:optional bool bool_type = false
    2:optional byte byte_type
    3:optional i16 i16_type
    4:optional i32 i32_type
    5:optional i64 i64_type
    6:optional double double_type
    7:optional string string_type
}

enum EnumExample {
    SUCCEED,
    FAILED
}

struct BaseRequest {
    1: required string traceId
    2: optional double param
    3: optional EnumExample param2 = EnumExample.SUCCEED
    4: optional Long userId
}

struct BaseResponse {
    1: required bool succeed
    2: optional i64 errorCode
    3: optional string errorMessage
    4: optional string data
}

exception BaseException {
    1: required Long errorCode
    2: required string errorMessage
    3: optional string data
}

struct ContainerTypeExample {
    1:optional list<i64> list_type,
    2:optional set<string> set_type,
    3:optional map<string, bool> map_type
}

service ServiceExample {
    BaseResponse read(1:BaseRequest req1, 2:BaseRequest req2) throws (1: BaseException e),

    void remove(1:BaseRequest req1),

    oneway void async_remove(1:BaseRequest req1),
}
