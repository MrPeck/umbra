/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: response.proto */

#ifndef PROTOBUF_C_response_2eproto__INCLUDED
#define PROTOBUF_C_response_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct ResponseHeader ResponseHeader;
typedef struct ExfiltrationResponse ExfiltrationResponse;
typedef struct InfiltrationResponse InfiltrationResponse;
typedef struct ReadDirResponse ReadDirResponse;
typedef struct ReadDirResponse__DirEntry ReadDirResponse__DirEntry;
typedef struct SuicideResponse SuicideResponse;


/* --- enums --- */

typedef enum _Status {
  STATUS__GOOD = 0,
  STATUS__OPEN_ERROR = 1,
  STATUS__READ_ERROR = 2,
  STATUS__WRITE_ERROR = 3,
  STATUS__STAT_ERROR = 4,
  STATUS__NOT_FILE = 5,
  STATUS__NOT_DIRECTORY = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(STATUS)
} Status;

/* --- messages --- */

struct  ResponseHeader
{
  ProtobufCMessage base;
  Status status;
  uint64_t size;
};
#define RESPONSE_HEADER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&response_header__descriptor) \
    , STATUS__GOOD, 0 }


struct  ExfiltrationResponse
{
  ProtobufCMessage base;
  ProtobufCBinaryData content;
};
#define EXFILTRATION_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&exfiltration_response__descriptor) \
    , {0,NULL} }


struct  InfiltrationResponse
{
  ProtobufCMessage base;
};
#define INFILTRATION_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&infiltration_response__descriptor) \
     }


struct  ReadDirResponse__DirEntry
{
  ProtobufCMessage base;
  uint32_t inode;
  uint32_t file_type;
  char *pathname;
};
#define READ_DIR_RESPONSE__DIR_ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&read_dir_response__dir_entry__descriptor) \
    , 0, 0, NULL }


struct  ReadDirResponse
{
  ProtobufCMessage base;
  size_t n_entries;
  ReadDirResponse__DirEntry **entries;
};
#define READ_DIR_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&read_dir_response__descriptor) \
    , 0,NULL }


struct  SuicideResponse
{
  ProtobufCMessage base;
};
#define SUICIDE_RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&suicide_response__descriptor) \
     }


/* ResponseHeader methods */
void   response_header__init
                     (ResponseHeader         *message);
size_t response_header__get_packed_size
                     (const ResponseHeader   *message);
size_t response_header__pack
                     (const ResponseHeader   *message,
                      uint8_t             *out);
size_t response_header__pack_to_buffer
                     (const ResponseHeader   *message,
                      ProtobufCBuffer     *buffer);
ResponseHeader *
       response_header__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   response_header__free_unpacked
                     (ResponseHeader *message,
                      ProtobufCAllocator *allocator);
/* ExfiltrationResponse methods */
void   exfiltration_response__init
                     (ExfiltrationResponse         *message);
size_t exfiltration_response__get_packed_size
                     (const ExfiltrationResponse   *message);
size_t exfiltration_response__pack
                     (const ExfiltrationResponse   *message,
                      uint8_t             *out);
size_t exfiltration_response__pack_to_buffer
                     (const ExfiltrationResponse   *message,
                      ProtobufCBuffer     *buffer);
ExfiltrationResponse *
       exfiltration_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   exfiltration_response__free_unpacked
                     (ExfiltrationResponse *message,
                      ProtobufCAllocator *allocator);
/* InfiltrationResponse methods */
void   infiltration_response__init
                     (InfiltrationResponse         *message);
size_t infiltration_response__get_packed_size
                     (const InfiltrationResponse   *message);
size_t infiltration_response__pack
                     (const InfiltrationResponse   *message,
                      uint8_t             *out);
size_t infiltration_response__pack_to_buffer
                     (const InfiltrationResponse   *message,
                      ProtobufCBuffer     *buffer);
InfiltrationResponse *
       infiltration_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   infiltration_response__free_unpacked
                     (InfiltrationResponse *message,
                      ProtobufCAllocator *allocator);
/* ReadDirResponse__DirEntry methods */
void   read_dir_response__dir_entry__init
                     (ReadDirResponse__DirEntry         *message);
/* ReadDirResponse methods */
void   read_dir_response__init
                     (ReadDirResponse         *message);
size_t read_dir_response__get_packed_size
                     (const ReadDirResponse   *message);
size_t read_dir_response__pack
                     (const ReadDirResponse   *message,
                      uint8_t             *out);
size_t read_dir_response__pack_to_buffer
                     (const ReadDirResponse   *message,
                      ProtobufCBuffer     *buffer);
ReadDirResponse *
       read_dir_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   read_dir_response__free_unpacked
                     (ReadDirResponse *message,
                      ProtobufCAllocator *allocator);
/* SuicideResponse methods */
void   suicide_response__init
                     (SuicideResponse         *message);
size_t suicide_response__get_packed_size
                     (const SuicideResponse   *message);
size_t suicide_response__pack
                     (const SuicideResponse   *message,
                      uint8_t             *out);
size_t suicide_response__pack_to_buffer
                     (const SuicideResponse   *message,
                      ProtobufCBuffer     *buffer);
SuicideResponse *
       suicide_response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   suicide_response__free_unpacked
                     (SuicideResponse *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*ResponseHeader_Closure)
                 (const ResponseHeader *message,
                  void *closure_data);
typedef void (*ExfiltrationResponse_Closure)
                 (const ExfiltrationResponse *message,
                  void *closure_data);
typedef void (*InfiltrationResponse_Closure)
                 (const InfiltrationResponse *message,
                  void *closure_data);
typedef void (*ReadDirResponse__DirEntry_Closure)
                 (const ReadDirResponse__DirEntry *message,
                  void *closure_data);
typedef void (*ReadDirResponse_Closure)
                 (const ReadDirResponse *message,
                  void *closure_data);
typedef void (*SuicideResponse_Closure)
                 (const SuicideResponse *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    status__descriptor;
extern const ProtobufCMessageDescriptor response_header__descriptor;
extern const ProtobufCMessageDescriptor exfiltration_response__descriptor;
extern const ProtobufCMessageDescriptor infiltration_response__descriptor;
extern const ProtobufCMessageDescriptor read_dir_response__descriptor;
extern const ProtobufCMessageDescriptor read_dir_response__dir_entry__descriptor;
extern const ProtobufCMessageDescriptor suicide_response__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_response_2eproto__INCLUDED */
