#ifndef LWIP_HDR_LWIPOPTS_H
#define LWIP_HDR_LWIPOPTS_H
#include <stdint.h>

// Overall settings.
//
#define NO_SYS                             1
#define SYS_LIGHTWEIGHT_PROT               0		  // We'll always be at the proper IRQL and locked.

// Modules.
//
#define LWIP_DNS                           1		  // Enable DNS.
#define LWIP_NETCONN                       0		  // Disable unnecessary modules.
#define LWIP_SOCKET                        0		  //
#define LWIP_DHCP                          0

// Module configuration.
//
#define LWIP_RANDOMIZE_INITIAL_LOCAL_PORTS 1
#define ARP_TABLE_SIZE                     64
#define LWIP_TCP_KEEPALIVE                 0 //1
#define TCP_MSS                            1460
#define TCP_SND_BUF                        0xFFFF
#define TCP_OVERSIZE                       TCP_MSS
#define LWIP_WND_SCALE                     1
#define TCP_RCV_SCALE                      8
#define TCP_WND                            (TCP_SND_BUF << TCP_RCV_SCALE)

// Memory settings.
//
#define MEM_LIBC_MALLOC                    1
#define MEMP_MEM_MALLOC                    1
#define MEM_SIZE                           (1024 * 1024)
#define IP_REASS_MAX_PBUFS                 64
#define PBUF_POOL_SIZE                     1024
#define MEMP_NUM_PBUF                      1024
#define MEMP_NUM_TCP_PCB                   32
#define MEMP_NUM_TCP_SEG                   512

#define TCP_TMR_INTERVAL                   10

// Debug options.
//
#if DEBUG_BUILD
	#define LWIP_STATS                         0//1
	//#define LWIP_DEBUG                         1
	//#define LWIP_DBG_MIN_LEVEL                 LWIP_DBG_LEVEL_WARNING//LWIP_DBG_LEVEL_ALL
	//#define LWIP_DBG_TYPES_ON                  0xFF
	//#define ETHARP_DEBUG                       LWIP_DBG_ON
	//#define DHCP_DEBUG                         LWIP_DBG_ON
	//#define ACD_DEBUG                          LWIP_DBG_ON
	//#define AUTOIP_DEBUG                       LWIP_DBG_ON
	//#define DNS_DEBUG                          LWIP_DBG_ON
	//#define TCP_DEBUG                          LWIP_DBG_ON
	//#define TCP_INPUT_DEBUG                    LWIP_DBG_ON
#else
	#define LWIP_STATS                         0
#endif

// Platform options.
//
#define __STRIGIFY( x ) #x
#define _STRIGIFY( x )  __STRIGIFY(x)
#ifdef __cplusplus
extern "C" {
#endif
	uint32_t __cdecl sys_rand();
	uint32_t __cdecl sys_jiffies();
	uint32_t __cdecl sys_now();
	int __cdecl printf( const char*, ... );
	void __cdecl _crt_exit_sz( const char* );
#ifdef __cplusplus
};
#endif

#if DEBUG_BUILD
#define LWIP_PLATFORM_ASSERT(x)            _crt_exit_sz( "Network assert fail '" x "' at " _STRIGIFY(__FILE__) ":" _STRIGIFY(__LINE__) )
#define LWIP_PLATFORM_DIAG(x)              printf x
#else
#define LWIP_PLATFORM_ASSERT(x)            _crt_exit_sz( "dGhpcyBpcyBhIG==" "Network assert fail '" x "' at " _STRIGIFY(__FILE__) ":" _STRIGIFY(__LINE__) )
#define LWIP_PLATFORM_DIAG(x)             
#endif

#define LWIP_RAND() sys_rand()

#endif /* LWIP_HDR_LWIPOPTS_H */