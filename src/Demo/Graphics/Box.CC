I64 global_r[4][4];

U0 DrawIt(CTask *,CDC *dc)
{
	I64 *old_r=dc->r;
	dc->thick=2;
	dc->color=RED;
	dc->x=200;
	dc->y=200;
	dc->flags|=DCF_TRANSFORMATION;
	DCMat4x4Set(dc,global_r); //This assigns to dc->r and sets r_norm.
	GrLine3(dc,-100,-100,-100, -100, 100,-100);
	GrLine3(dc,-100, 100,-100,	100, 100,-100);
	GrLine3(dc, 100, 100,-100,	100,-100,-100);
	GrLine3(dc, 100,-100,-100, -100,-100,-100);
	GrLine3(dc,-100,-100, 100, -100, 100, 100);
	GrLine3(dc,-100, 100, 100,	100, 100, 100);
	GrLine3(dc, 100, 100, 100,	100,-100, 100);
	GrLine3(dc, 100,-100, 100, -100,-100, 100);
	GrLine3(dc,-100,-100, 100, -100,-100,-100);
	GrLine3(dc,-100, 100, 100, -100, 100,-100);
	GrLine3(dc, 100, 100, 100,	100, 100,-100);
	GrLine3(dc, 100,-100, 100,	100,-100,-100);
	dc->r=old_r;
}

U0 Box()
{
	F64 �=0,�=0,�=0,s=1,s1=1.05;
	SettingsPush; //See $LK,"SettingsPush",A="MN:SettingsPush"$
	DocClear;
	Fs->draw_it=&DrawIt;
	while (!CharScan) {
		Mat4x4IdentEqu(global_r);
		Mat4x4RotZ(global_r,�);
		Mat4x4RotX(global_r,�);
		Mat4x4RotZ(global_r,�);
		Mat4x4Scale(global_r,s);

		Sleep(20);
		�+=2*�/70;
		�+=2*�/90;
		�+=2*�/110;
		s*=s1;
		if ( !(0.2<s<1.4) ) s1=1/s1;
	}
	SettingsPop;
}

Box;
