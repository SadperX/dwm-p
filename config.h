/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 8;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 5;        /* horizontal padding for statusbar */
static const int vertpadbar         = 10;        /* vertical padding for statusbar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = { "Iosevka Nerd Font:size=11" };
static const char dmenufont[]       = "Iosevka Nerd Font:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_lightblue[]   = "#7aa2f7";
static const char col_turquesa[]    = "#2ac3de";
static const char col_purple[]      = "#9d7cd8";
static const char col_orange[]      = "#ff9e64";
static const char col_yellow[]      = "#e0af68";
static const char col_lightcyan[]   = "#b4f9f8";
static const char col_green[]       = "#73daca";
static const char col_lightpurple[] = "#c0caf5";

static const char d_col_cyan[]        = "#005577";
static const char d_col_lightblue[]   = "#4d7db3";
static const char d_col_turquesa[]    = "#1d9baf";
static const char d_col_purple[]      = "#7a5cb4";
static const char d_col_orange[]      = "#d98040";
static const char d_col_yellow[]      = "#b88b4f";
static const char d_col_lightcyan[]   = "#8dc4c5";
static const char d_col_green[]       = "#54a8a6";
static const char d_col_lightpurple[] = "#8d92b8";

static const char col_red[]           = "#ff9e64";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const char *const autostart[] = {
	"picom", "--config", "/home/sadper/.config/picom/picom.conf", NULL,
	"nitrogen", "--restore", NULL,
    "xmodmap", "/home/sadper/.xmodmap", NULL,
	NULL /* terminate */
};

static const char *tagsel[][2] = {
   /*   fg         bg    */
  { col_cyan       , col_gray1 }, /* norm1 */
  { col_lightblue  , col_gray1 }, /* norm2 */
  { col_turquesa   , col_gray1 }, /* norm3 */
  { col_purple     , col_gray1 }, /* norm4 */
  { col_orange     , col_gray1 }, /* norm5 */
  { col_yellow     , col_gray1 }, /* norm6 */
  { col_lightcyan  , col_gray1 }, /* norm7 */
  { col_green      , col_gray1 }, /* norm8 */
  { col_lightpurple, col_gray1 }, /* norm9 */

  { col_cyan       , col_gray1 }, /* sel1 */
  { col_lightblue  , col_gray1 }, /* sel2 */
  { col_turquesa   , col_gray1 }, /* sel3 */
  { col_purple     , col_gray1 }, /* sel4 */
  { col_orange     , col_gray1 }, /* sel5 */
  { col_yellow     , col_gray1 }, /* sel6 */
  { col_lightcyan  , col_gray1 }, /* sel7 */
  { col_green      , col_gray1 }, /* sel8 */
  { col_lightpurple, col_gray1 }, /* sel9 */

  { d_col_cyan       , col_gray1 }, /* occ but not sel1 */
  { d_col_lightblue  , col_gray1 }, /* occ but not sel2 */
  { d_col_turquesa   , col_gray1 }, /* occ but not sel3 */
  { d_col_purple     , col_gray1 }, /* occ but not sel4 */
  { d_col_orange     , col_gray1 }, /* occ but not sel5 */
  { d_col_yellow     , col_gray1 }, /* occ but not sel6 */
  { d_col_lightcyan  , col_gray1 }, /* occ but not sel7 */
  { d_col_green      , col_gray1 }, /* occ but not sel8 */
  { d_col_lightpurple, col_gray1 }, /* occ but not sel9 */

  { d_col_cyan       , col_gray3 }, /* has pinned tag1 */
  { d_col_lightblue  , col_gray3 }, /* has pinned tag2 */
  { d_col_turquesa   , col_gray3 }, /* has pinned tag3 */
  { d_col_purple     , col_gray3 }, /* has pinned tag4 */
  { d_col_orange     , col_gray3 }, /* has pinned tag5 */
  { d_col_yellow     , col_gray3 }, /* has pinned tag6 */
  { d_col_lightcyan  , col_gray3 }, /* has pinned tag7 */
  { d_col_green      , col_gray3 }, /* has pinned tag8 */
  { d_col_lightpurple, col_gray3 }, /* has pinned tag9 */
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-x", "10", "-y", "10", "-z", "1340", "-l", "0", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4,  NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },

	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },

	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },

	/*{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },*/
	/*{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },*/
	/*{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },*/

	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	/*{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },*/
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

