 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
static au_event_t	aui_fchownat(au_event_t);
static au_event_t	aui_openat(au_event_t);
static au_event_t	aui_unlinkat(au_event_t);
static au_event_t	aui_fstatat(au_event_t);
static void	aus_openat(struct t_audit_data *);
static void	aus_fchownat(struct t_audit_data *);
aui_null,	AUE_NULL,	aus_null,	/* 2 (loadable) was forkall */
aui_null,	AUE_NULL,	aus_null,	/* 7 (loadable) was wait */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 8 (loadable) was creat */
aui_null,	AUE_NULL,	aus_null,	/* 11 (loadable) was exec */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 22 (loadable) was umount */
aui_null,	AUE_NULL,	aus_null,	/* 26 pcsample */
aui_null,	AUE_NULL,	aus_null,	/* 30 (loadable) was utime */
aui_null,	AUE_NULL,	aus_null,	/* 41 (loadable) was dup */
aui_null,	AUE_PIPE,	aus_null,	/* 42 (loadable) pipe */
aui_null,	AUE_ACCESS,	aus_null,	/* 45 faccessat */
		auf_null,	S2E_PUB | S2E_ATC,
aui_null,	AUE_NULL,	aus_null,	/* 48 (loadable) was ssig */
aui_msgsys,	AUE_MSGSYS,	aus_msgsys,	/* 49 (loadable) msgsys */
aui_null,	AUE_ACCT,	aus_acct,	/* 51 (loadable) sysacct */
aui_shmsys,	AUE_SHMSYS,	aus_shmsys,	/* 52 (loadable) shmsys */
aui_semsys,	AUE_SEMSYS,	aus_semsys,	/* 53 (loadable) semsys */
aui_fchownat,	AUE_NULL,	aus_fchownat,	/* 56 fchownat */
		auf_null,	S2E_ATC,
aui_null,	AUE_RENAME,	aus_null,	/* 64 renameat */
		auf_null,	S2E_ATC,
aui_unlinkat,	AUE_NULL,	aus_null,	/* 65 unlinkat */
		auf_null,	S2E_ATC,
aui_fstatat,	AUE_NULL,	aus_null,	/* 66 fstatat */
		auf_null,	S2E_PUB | S2E_ATC,
aui_fstatat,	AUE_NULL,	aus_null,	/* 67 fstatat64 */
		auf_null,	S2E_PUB | S2E_ATC,
aui_openat,	AUE_OPEN,	aus_openat,	/* 68 openat */
		auf_null,	S2E_SP | S2E_ATC,
aui_openat,	AUE_OPEN,	aus_openat,	/* 69 openat64 */
		auf_null,	S2E_SP | S2E_ATC,
aui_null,	AUE_NULL,	aus_null,	/* 70 tasksys */
aui_null,	AUE_NULL,	aus_null,	/* 71 (loadable) acctctl */
aui_null,	AUE_NULL,	aus_null,	/* 72 (loadable) exacct */
aui_null,	AUE_NULL,	aus_null,	/* 73 getpagesizes */
aui_null,	AUE_NULL,	aus_null,	/* 74 rctlsys */
aui_null,	AUE_NULL,	aus_null,	/* 76 (loadable) was fsat */
aui_null,	AUE_NULL,	aus_null,	/* 77 syslwp_park */
aui_null,	AUE_NULL,	aus_null,	/* 78 sendfilev */
aui_null,	AUE_NULL,	aus_null,	/* 83 ucredsys */
aui_null,	AUE_NULL,	aus_null,	/* 87 (loadable) was poll */
aui_null,	AUE_NULL,	aus_null,	/* 101 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 105 getloadavg */
aui_null,	AUE_NULL,	aus_null,	/* 107 waitsys */
aui_null,	AUE_NULL,	aus_null,	/* 108 sigsendsys */
aui_null,	AUE_UTIMES,	aus_null,	/* 110 utimesys */
		auf_null,	S2E_ATC,
aui_null,	AUE_NULL,	aus_null,	/* 111 sigresend */
aui_null,	AUE_PRIOCNTLSYS, aus_priocntlsys, /* 112 priocntlsys */
aui_null,	AUE_NULL,	aus_null,	/* 123 (loadable) was xstat */
aui_null,	AUE_NULL,	aus_null,	/* 124 (loadable) was lxstat */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 125 (loadable) was fxstat */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 126 (loadable) was xmknod */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 127 mmapobj */
aui_null,	AUE_NULL,	aus_null,	/* 140 (loadable) sharefs */
aui_null,	AUE_NULL,	aus_null,	/* 143 (loadable) was fork1 */
aui_null,	AUE_NULL,	aus_null,	/* 147 (loadable) */
						/*	was lwp_sema_wait */
aui_null,	AUE_NULL,	aus_null,	/* 150 lwp_detach */
aui_null,	AUE_NULL,	aus_null,	/* 151 corectl */
aui_null,	AUE_NULL,	aus_null,	/* 154 (loadable) was utimes */
aui_null,	AUE_NULL,	aus_null,	/* 165 lwp_sigmask */
aui_null,	AUE_NULL,	aus_null,	/* 166 lwp_private */
aui_null,	AUE_NULL,	aus_null,	/* 169 (loadable) */
						/*	was lwp_mutex_lock */
aui_null,	AUE_INST_SYNC,	aus_inst_sync,  /* 176 (loadable) inst_sync */
aui_null,	AUE_NULL,	aus_null,	/* 178 (loadable) kaio */
aui_null,	AUE_NULL,	aus_null,	/* 179 (loadable) cpc */
aui_null,	AUE_NULL,	aus_null,	/* 180 lgrpsys */
aui_null,	AUE_NULL,	aus_null,	/* 181 rusagesys */
aui_null,	AUE_NULL,	aus_null,	/* 183 pollsys */
aui_null,	AUE_PROCESSOR_BIND, aus_processor_bind, /* 187 processor_bind */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 208 sparc_utrap_install */
aui_null,	AUE_NULL,	aus_null,	/* 213 getdents64 */
aui_null,	AUE_NULL,	aus_null,	/* 224 (loadable) was creat64 */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 227 zone */
aui_null,	AUE_NULL,	aus_null,	/* 228 (loadable) autofssys */
aui_null,	AUE_NULL,	aus_null,	/* 229 getcwd */
aui_null,	AUE_NTP_ADJTIME, aus_null,	/* 249 ntp_adjtime */
static au_event_t
aui_fchownat(au_event_t e)
{
	klwp_t *clwp = ttolwp(curthread);

	struct a {
		long	fd;
		long	fname;		/* char * */
		long	uid;
		long	gid;
		long	flags;
	} *uap = (struct a *)clwp->lwp_ap;

	if (uap->fname == NULL)
		e = AUE_FCHOWN;
	else if (uap->flags & AT_SYMLINK_NOFOLLOW)
		e = AUE_LCHOWN;
	else
		e = AUE_CHOWN;

	return (e);
}

/*ARGSUSED*/
static void
aus_fchownat(struct t_audit_data *tad)
{
	klwp_t *clwp = ttolwp(curthread);
	uint32_t uid, gid;

	struct a {
		long	fd;
		long	fname;		/* char * */
		long	uid;
		long	gid;
		long	flags;
	} *uap = (struct a *)clwp->lwp_ap;

	uid = (uint32_t)uap->uid;
	gid = (uint32_t)uap->gid;

	au_uwrite(au_to_arg32(3, "new file uid", uid));
	au_uwrite(au_to_arg32(4, "new file gid", gid));
}

/*
 * convert open mode to appropriate open event
 */
au_event_t
open_event(uint_t fm)
{
	au_event_t e;

	switch (fm & (O_RDONLY|O_WRONLY|O_RDWR|O_CREAT|O_TRUNC)) {
	case O_RDONLY:
		e = AUE_OPEN_R;
		break;
	case O_RDONLY | O_CREAT:
		e = AUE_OPEN_RC;
		break;
	case O_RDONLY | O_TRUNC:
		e = AUE_OPEN_RT;
		break;
	case O_RDONLY | O_TRUNC | O_CREAT:
		e = AUE_OPEN_RTC;
		break;
	case O_WRONLY:
		e = AUE_OPEN_W;
		break;
	case O_WRONLY | O_CREAT:
		e = AUE_OPEN_WC;
		break;
	case O_WRONLY | O_TRUNC:
		e = AUE_OPEN_WT;
		break;
	case O_WRONLY | O_TRUNC | O_CREAT:
		e = AUE_OPEN_WTC;
		break;
	case O_RDWR:
		e = AUE_OPEN_RW;
		break;
	case O_RDWR | O_CREAT:
		e = AUE_OPEN_RWC;
		break;
	case O_RDWR | O_TRUNC:
		e = AUE_OPEN_RWT;
		break;
	case O_RDWR | O_TRUNC | O_CREAT:
		e = AUE_OPEN_RWTC;
		break;
	default:
		e = AUE_NULL;
		break;
	}
	return (e);
}

/* ARGSUSED */
	t_audit_data_t *tad = T2A(curthread);
	/* convert to appropriate au_ctrl */
	if (fm & (FXATTR | FXATTRDIROPEN))
		tad->tad_ctrl |= PAD_ATTPATH;
	return (open_event(fm));
	if ((fm & (O_RDONLY|O_WRONLY|O_RDWR|O_CREAT|O_TRUNC)) == O_RDONLY)
/* ARGSUSED */
aui_openat(au_event_t e)
	t_audit_data_t *tad = T2A(curthread);
	uint_t fm;

		long	filedes;
		long	fnamep;		/* char	* */
		long	fmode;
		long	cmode;
	fm = (uint_t)uap->fmode;
	/* convert to appropriate au_ctrl */
	if (fm & (FXATTR | FXATTRDIROPEN))
		tad->tad_ctrl |= PAD_ATTPATH;
	return (open_event(fm));
}
static void
aus_openat(struct t_audit_data *tad)
{
	klwp_t *clwp = ttolwp(curthread);
	uint_t fm;
	struct a {
		long	filedes;
		long	fnamep;		/* char	* */
		long	fmode;
		long	cmode;
	} *uap = (struct a *)clwp->lwp_ap;
	fm = (uint_t)uap->fmode;
	/* If no write, create, or trunc modes, mark as a public op */
	if ((fm & (O_RDONLY|O_WRONLY|O_RDWR|O_CREAT|O_TRUNC)) == O_RDONLY)
		tad->tad_ctrl |= PAD_PUBLIC_EV;
static au_event_t
aui_unlinkat(au_event_t e)

		long	filedes;
		long	fnamep;		/* char	* */
		long	flags;
	if (uap->flags & AT_REMOVEDIR)
		e = AUE_RMDIR;
	else
		e = AUE_UNLINK;
	return (e);
}
static au_event_t
aui_fstatat(au_event_t e)
{
	klwp_t *clwp = ttolwp(curthread);
	struct a {
		long	filedes;
		long	fnamep;		/* char	* */
		long	statb;
		long	flags;
	} *uap = (struct a *)clwp->lwp_ap;

	if (uap->fnamep == NULL)
		e = AUE_FSTAT;
	else if (uap->flags & AT_SYMLINK_NOFOLLOW)
		e = AUE_LSTAT;
	else
		e = AUE_STAT;

	return (e);