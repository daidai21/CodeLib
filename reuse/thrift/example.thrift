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

// ==================================================================
// RPC

service ServiceExample {
    BaseResponse read(1:BaseRequest req1, 2:BaseRequest req2) throws (1: BaseException e),

    void remove(1:BaseRequest req1),

    oneway void async_remove(1:BaseRequest req1),
}

// ==================================================================
// HTTP

// Ref  https://www.cloudwego.io/zh/docs/kitex/tutorials/advanced-feature/generic_call/
struct ReqItem {
    1: optional i64 id(go.tag = "json:\"id\"")
    2: optional string text
}

struct BizRequest {
    1: optional i64 v_int64(api.query = 'v_int64', api.vd = "$>0&&$<200")
    2: optional string text(api.body = 'text')
    3: optional i32 token(api.header = 'token')
    4: optional map<i64, ReqItem> req_items_map (api.body='req_items_map')
    5: optional ReqItem some(api.body = 'some')
    6: optional list<string> req_items(api.query = 'req_items')
    7: optional i32 api_version(api.path = 'action')
    8: optional i64 uid(api.path = 'biz')
    9: optional list<i64> cids(api.query = 'cids')
    10: optional list<string> vids(api.query = 'vids')
}
struct RspItem {
    1: optional i64 item_id
    2: optional string text
}

struct BizResponse {
    1: optional string T                             (api.header= 'T')
    2: optional map<i64, RspItem> rsp_items           (api.body='rsp_items')
    3: optional i32 v_enum                       (api.none = '')
    4: optional list<RspItem> rsp_item_list            (api.body = 'rsp_item_list')
    5: optional i32 http_code                         (api.http_code = '')
    6: optional list<i64> item_count (api.header = 'item_count')
}

service BizService {
    BizResponse BizMethod1(1: BizRequest req)(api.get = '/life/client/:action/:biz', api.baseurl = 'ib.snssdk.com', api.param = 'true')
    BizResponse BizMethod2(1: BizRequest req)(api.post = '/life/client/:action/:biz', api.baseurl = 'ib.snssdk.com', api.param = 'true', api.serializer = 'form')
    BizResponse BizMethod3(1: BizRequest req)(api.post = '/life/client/:action/:biz/other', api.baseurl = 'ib.snssdk.com', api.param = 'true', api.serializer = 'json')
}

struct BaseHttpRequest {
    1: optional string header (api.header = 'token')
    2: optional string json_header(api.header = 'json_header')
    // etc...
}

service HttpServiceExample {

    BaseResponse read(1:BaseRequest req) (api.get = "url path", )
}
