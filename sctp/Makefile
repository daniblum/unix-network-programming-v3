include ../Make.defines

PROGS =	sctpserv01 sctpclient01 sctpserv02 sctpserv03 sctpclient02 sctpserv04 \
sctpserv05 sctpclient03 sctpserv06 sctpserv07 sctpclient04 sctpserv_fork

LIBS+= -L/usr/local/v6/lib -L../unp -lm -lsctp

WRAPPER= sctp_wrapper.o

GETNBRSTRM= sctp_getnostrm.o sctp_addr_to_associd.o

.c.lc:
	../../troff/fixcode.sh $< > $@
.h.lh:
	../../troff/fixcode.sh $< > $@

CFLAGS+= -g
.c.o:
	${CC} ${CFLAGS} -c $<

all:	${PROGS}

sctpserv01:	sctpserv01.o ${WRAPPER} ${GETNBRSTRM}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}


sctpclient01:   sctpclient01.o sctp_strcli.o sctp_strcliecho.o ${WRAPPER}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}


sctpserv02:	sctpserv02.o ${WRAPPER} ${GETNBRSTRM}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpserv03:	sctpserv03.o ${WRAPPER} ${GETNBRSTRM} 
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpserv04:	sctpserv04.o ${WRAPPER} ${GETNBRSTRM} 
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpserv05:	sctpserv05.o sctp_pdapircv.o ${WRAPPER} ${GETNBRSTRM} 
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpserv06:	sctpserv06.o sctp_displayevents.o ${WRAPPER} ${GETNBRSTRM} 
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpclient02:	sctpclient02.o sctp_strcli.o sctp_strcliecho.o ${WRAPPER}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpclient03:  sctpclient01.o sctp_strcli_un.o sctp_strcliecho.o ${WRAPPER}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpserv07:	sctpserv07.o sctp_displayevents.o sctp_bindargs.o ${WRAPPER} 
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}


sctpclient04:	sctpclient04.o sctp_strcli1.o sctp_check_notify.o sctp_print_addrs.o sctp_modify_hb.o ${WRAPPER}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sctpserv_fork:  sctpserv_fork.o sctp_addr_to_associd.o ${WRAPPER}
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
		rm -f ${PROGS} ${CLEANFILES}
