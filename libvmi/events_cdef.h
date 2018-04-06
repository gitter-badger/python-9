#define VMI_EVENTS_VERSION 0x00000004

#define VMI_EVENT_INVALID 0
#define VMI_EVENT_MEMORY 1
#define VMI_EVENT_REGISTER 2
#define VMI_EVENT_SINGLESTEP 3
#define VMI_EVENT_INTERRUPT 4
#define VMI_EVENT_GUEST_REQUEST 5
#define VMI_EVENT_CPUID 6
#define VMI_EVENT_DEBUG_EXCEPTION 7
#define VMI_EVENT_PRIVILEGED_CALL 8
#define VMI_EVENT_DESCRIPTOR_ACCESS 9

struct vmi_event;
typedef struct vmi_event vmi_event_t;

// structs
typedef struct {
    ...;
} reg_event_t;

typedef uint8_t vmi_mem_access_t;

#define VMI_MEMACCESS_INVALID     ...
#define VMI_MEMACCESS_N           ...
#define VMI_MEMACCESS_R           ...
#define VMI_MEMACCESS_W           ...
#define VMI_MEMACCESS_X           ...
#define VMI_MEMACCESS_RW          ...
#define VMI_MEMACCESS_RX          ...
#define VMI_MEMACCESS_WX          ...
#define VMI_MEMACCESS_RWX         ...
#define VMI_MEMACCESS_W2X         ...
#define VMI_MEMACCESS_RWX2N       ...

typedef struct {
    ...;
} mem_access_event_t;

typedef struct {
    ...;
} interrupt_event_t;

typedef struct {
    ...;
} single_step_event_t;

typedef struct {
    ...;
} debug_event_t;

typedef struct {
    ...;
} cpuid_event_t;

typedef struct desriptor_event {
    ...;
} descriptor_event_t;

struct vmi_event {
    ...;
};

typedef uint32_t event_response_t;

extern "Python" event_response_t generic_event_callback(
    vmi_instance_t vmi,
    vmi_event_t *event);

status_t vmi_register_event(
    vmi_instance_t vmi,
    vmi_event_t *event);

status_t vmi_events_listen(
    vmi_instance_t vmi,
    uint32_t timeout);