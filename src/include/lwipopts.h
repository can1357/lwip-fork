#ifndef LWIP_HDR_LWIPOPTS_H
#define LWIP_HDR_LWIPOPTS_H
#include <stdint.h>

// Overall configuration.
//
#define NO_SYS                             1
#define SYS_LIGHTWEIGHT_PROT               0		  // We'll always be at the proper IRQL and locked.

// Modules.
//
#define LWIP_DNS                           1		  // Enable DNS.
#define LWIP_NETCONN                       0		  // Disable unnecessary modules.
#define LWIP_SOCKET                        0		  //
#define LWIP_DHCP                          0
#define LWIP_STATS                         0

// Module configuration.
//
#define LWIP_RANDOMIZE_INITIAL_LOCAL_PORTS 1
#define ARP_TABLE_SIZE                     64
#define DNS_MAX_TTL                        60

// TCP/IP configuration.
//
#define IP_REASS_MAX_PBUFS				   0xFFFFFFFF
#define LWIP_WND_SCALE                     1
#define TCP_RCV_SCALE                      5
#define TCP_MSS                            1460
#define TCP_WND                            0xffff
#define TCP_SND_BUF                        TCP_WND
#define TCP_SND_QUEUELEN                   TCP_SNDQUEUELEN_OVERFLOW
#define TCP_TMR_INTERVAL				   100
#define TCP_OVERSIZE                       TCP_MSS
#define LWIP_TCP_TIMESTAMPS                1
#define LWIP_TCP_KEEPALIVE                 1
#define LWIP_TCP_SACK_OUT                  0
#define TCP_QUEUE_OOSEQ                    1
#define CHECKSUM_CHECK_IP                  1
#define CHECKSUM_CHECK_TCP                 0
#define CHECKSUM_CHECK_UDP                 1
#define LWIP_CHECKSUM_ON_COPY              1

// Memory configuration.
//
#define MEM_LIBC_MALLOC                    1
#define MEMP_MEM_MALLOC                    1
#define MEM_SIZE                           (1024 * 1024 * 1024)
#define PBUF_POOL_SIZE                     32768
#define PBUF_POOL_BUFSIZE                  4096
#define MEMP_NUM_PBUF                      4096
#define MEMP_NUM_TCP_PCB                   32
#define MEMP_NUM_TCP_SEG                   4096

// Platform options.
//
#define __STRIGIFY( x ) #x
#define _STRIGIFY( x )  __STRIGIFY(x)
#ifdef __cplusplus
extern "C" {
#endif
	void __cdecl sys_assert_core_locked();
	uint32_t __cdecl sys_rand();
	uint32_t __cdecl sys_jiffies();
	uint32_t __cdecl sys_now();
	int __cdecl printf( const char*, ... );
	void __cdecl _crt_exit_sz( const char* );
#ifdef __cplusplus
};
#endif

// Debug.
//
//#define LWIP_DEBUG                         0
//#define LWIP_DBG_MIN_LEVEL                 LWIP_DBG_LEVEL_ALL // LWIP_DBG_LEVEL_ALL
//#define LWIP_DBG_TYPES_ON                  0xF7
//#define ETHARP_DEBUG                       LWIP_DBG_OFF
//#define NETIF_DEBUG                        LWIP_DBG_OFF
//#define PBUF_DEBUG                         LWIP_DBG_OFF
//#define API_LIB_DEBUG                      LWIP_DBG_ON
//#define API_MSG_DEBUG                      LWIP_DBG_ON
//#define SOCKETS_DEBUG                      LWIP_DBG_OFF
//#define ICMP_DEBUG                         LWIP_DBG_OFF
//#define IGMP_DEBUG                         LWIP_DBG_OFF
//#define INET_DEBUG                         LWIP_DBG_ON
//#define IP_DEBUG                           LWIP_DBG_ON
//#define IP_REASS_DEBUG                     LWIP_DBG_ON
//#define RAW_DEBUG                          LWIP_DBG_OFF
//#define MEM_DEBUG                          LWIP_DBG_OFF
//#define MEMP_DEBUG                         LWIP_DBG_OFF
//#define SYS_DEBUG                          LWIP_DBG_OFF
//#define TIMERS_DEBUG                       LWIP_DBG_OFF
//#define TCP_DEBUG                          LWIP_DBG_ON
//#define TCP_INPUT_DEBUG                    LWIP_DBG_ON
//#define TCP_FR_DEBUG                       LWIP_DBG_ON
//#define TCP_RTO_DEBUG                      LWIP_DBG_ON
//#define TCP_CWND_DEBUG                     LWIP_DBG_ON
//#define TCP_WND_DEBUG                      LWIP_DBG_ON
//#define TCP_OUTPUT_DEBUG                   LWIP_DBG_ON
//#define TCP_RST_DEBUG                      LWIP_DBG_ON
//#define TCP_QLEN_DEBUG                     LWIP_DBG_ON
//#define UDP_DEBUG                          LWIP_DBG_ON
//#define TCPIP_DEBUG                        LWIP_DBG_ON
//#define SLIP_DEBUG                         LWIP_DBG_OFF
//#define DHCP_DEBUG                         LWIP_DBG_OFF
//#define AUTOIP_DEBUG                       LWIP_DBG_OFF
//#define ACD_DEBUG                          LWIP_DBG_OFF
//#define DNS_DEBUG                          LWIP_DBG_OFF
//#define IP6_DEBUG                          LWIP_DBG_OFF
//#define DHCP6_DEBUG                        LWIP_DBG_OFF

#if DEBUG_BUILD
#define LWIP_PLATFORM_ASSERT(x)            _crt_exit_sz( "Network assert fail '" x "' at " _STRIGIFY(__FILE__) ":" _STRIGIFY(__LINE__) )
#define LWIP_PLATFORM_DIAG(x)              printf x
#else
#define LWIP_PLATFORM_ASSERT(x)            _crt_exit_sz( "dGhpcyBpcyBhIG==" "Network assert fail '" x "' at " _STRIGIFY(__FILE__) ":" _STRIGIFY(__LINE__) )
#define LWIP_PLATFORM_DIAG(x)              //printf x
#endif

#define LWIP_RAND() sys_rand()
#define LWIP_ASSERT_CORE_LOCKED() sys_assert_core_locked()

#endif /* LWIP_HDR_LWIPOPTS_H */