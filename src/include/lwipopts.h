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

// TCP/IP configuration.
//
#define IP_REASS_MAX_PBUFS						 0xFFFFFFFF
#define TCP_MSS                            1460
#define TCP_WND                            0xFFFF
#define TCP_SND_BUF                        TCP_WND
#define LWIP_WND_SCALE                     1
#define TCP_RCV_SCALE                      8
#define TCP_SND_QUEUELEN                   TCP_SNDQUEUELEN_OVERFLOW
#define TCP_TMR_INTERVAL						 200
#define TCP_OVERSIZE                       TCP_MSS
#define LWIP_TCP_TIMESTAMPS                1
#define LWIP_TCP_KEEPALIVE                 1
#define TCP_QUEUE_OOSEQ                    1
#define CHECKSUM_CHECK_IP                  1
#define CHECKSUM_CHECK_TCP                 1
#define CHECKSUM_CHECK_UDP                 1

// Memory configuration.
//
#define MEM_LIBC_MALLOC                    1
#define MEMP_MEM_MALLOC                    1
#define MEM_SIZE                           (1024 * 1024 * 1024)
#define PBUF_POOL_SIZE                     4096
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
#define LWIP_DEBUG                         1
#define LWIP_DBG_MIN_LEVEL                 LWIP_DBG_LEVEL_WARNING // LWIP_DBG_LEVEL_ALL
#define LWIP_DBG_TYPES_ON                  0xF7
#define ETHARP_DEBUG                       LWIP_DBG_ON
#define NETIF_DEBUG                        LWIP_DBG_ON
#define PBUF_DEBUG                         LWIP_DBG_ON
#define API_LIB_DEBUG                      LWIP_DBG_ON
#define API_MSG_DEBUG                      LWIP_DBG_ON
#define SOCKETS_DEBUG                      LWIP_DBG_ON
#define ICMP_DEBUG                         LWIP_DBG_ON
#define IGMP_DEBUG                         LWIP_DBG_ON
#define INET_DEBUG                         LWIP_DBG_ON
#define IP_DEBUG                           LWIP_DBG_ON
#define IP_REASS_DEBUG                     LWIP_DBG_ON
#define RAW_DEBUG                          LWIP_DBG_ON
#define MEM_DEBUG                          LWIP_DBG_ON
#define MEMP_DEBUG                         LWIP_DBG_ON
#define SYS_DEBUG                          LWIP_DBG_ON
#define TIMERS_DEBUG                       LWIP_DBG_ON
#define TCP_DEBUG                          LWIP_DBG_ON
#define TCP_INPUT_DEBUG                    LWIP_DBG_ON
#define TCP_FR_DEBUG                       LWIP_DBG_ON
#define TCP_RTO_DEBUG                      LWIP_DBG_ON
#define TCP_CWND_DEBUG                     LWIP_DBG_ON
#define TCP_WND_DEBUG                      LWIP_DBG_ON
#define TCP_OUTPUT_DEBUG                   LWIP_DBG_ON
#define TCP_RST_DEBUG                      LWIP_DBG_ON
#define TCP_QLEN_DEBUG                     LWIP_DBG_ON
#define UDP_DEBUG                          LWIP_DBG_ON
#define TCPIP_DEBUG                        LWIP_DBG_ON
#define SLIP_DEBUG                         LWIP_DBG_ON
#define DHCP_DEBUG                         LWIP_DBG_ON
#define AUTOIP_DEBUG                       LWIP_DBG_ON
#define ACD_DEBUG                          LWIP_DBG_ON
#define DNS_DEBUG                          LWIP_DBG_ON
#define IP6_DEBUG                          LWIP_DBG_ON
#define DHCP6_DEBUG                        LWIP_DBG_ON

#if DEBUG_BUILD
#define LWIP_PLATFORM_ASSERT(x)            _crt_exit_sz( "Network assert fail '" x "' at " _STRIGIFY(__FILE__) ":" _STRIGIFY(__LINE__) )
#define LWIP_PLATFORM_DIAG(x)              printf x
#else
#define LWIP_PLATFORM_ASSERT(x)            _crt_exit_sz( "dGhpcyBpcyBhIG==" "Network assert fail '" x "' at " _STRIGIFY(__FILE__) ":" _STRIGIFY(__LINE__) )
#define LWIP_PLATFORM_DIAG(x)              printf x
#endif

#define LWIP_RAND() sys_rand()

#endif /* LWIP_HDR_LWIPOPTS_H */