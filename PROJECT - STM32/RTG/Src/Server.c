#include "RTG.h"
// Server == NUCLEOF746ZG

// callback of UDP receive
void udp_receive_callback(
		void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port
) {
	/* Get the IP of the Client */
	const char* remoteIP = ipaddr_ntoa(addr); // remote IP

#if GET_FROM_SOCKET == 1
	const int len = sprintf (buffer, "Hello %s From UDP SERVER\n", (char*)p->payload);
#else
	char buf[100]; // buffer
	const int len = sprintf (buf, "Hello %s From UDP SERVER\n", (char*)p->payload);
#endif

	/* allocate pbuf from RAM*/
	struct pbuf *txBuf = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_RAM);

	/* copy the data into the buffer  */
#if GET_FROM_SOCKET == 1
	pbuf_take(txBuf, buffer, len);
#else
	pbuf_take(txBuf, buf, len);
#endif

	/* Connect to the remote client */
	udp_connect(upcb, addr, port);

	/* Send a Reply to the Client */
	udp_send(upcb, txBuf);

	/* free the UDP connection, so we can accept new clients */
	udp_disconnect(upcb);

	/* Free the p_tx buffer */
	pbuf_free(txBuf);

	/* Free the p buffer */
	pbuf_free(p);
}

// initializer of UDP Server
void udpServer_init(void) {
	// UDP Control Block structure
   struct udp_pcb* upcb = udp_new();
   err_t err = udp_bind(upcb, IP_ADDR_ANY, SERVER_PORT);  // 7 is the server UDP port

   /* Set a receive callback for the upcb */
   if (err == ERR_OK) {
	   udp_recv(upcb, udp_receive_callback, NULL);
   }
   else {
	   udp_remove(upcb);
   }
}
