#include	"unp.h"

void
sctp_print_addresses(struct sockaddr *addrs, int num)
{
	struct sockaddr_storage *ss;
	int i,salen=0;

	ss = (struct sockaddr_storage *) addrs;
	for(i=0; i<num; i++){
#ifdef HAVE_SOCKADDR_SA_LEN
		salen = ss->ss_len;
#else
		switch(ss->ss_family) {
		case AF_INET:
			salen = sizeof(struct sockaddr_in);
			break;
#ifdef IPV6
		case AF_INET6:
			salen = sizeof(struct sockaddr_in6);
			break;
#endif
		default:
			err_quit("sctp_print_addresses: unknown AF");
			break;
		}
#endif
		printf("%s\n", Sock_ntop((SA *)ss, salen));
		ss = (struct sockaddr_storage *)((char *)ss + salen);
	}
}
