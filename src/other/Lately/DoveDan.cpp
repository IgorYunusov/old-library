/*

	File : DoveDan.cpp

	GuGuDan

	for dc programming galler


	<!--
	[Note: This is a slightly edited transcript of the talk. As such it contains fal
	se starts, as well as locutions that are natural in spoken English but look stra
	nge in print. It is not clear how to correct them to written English style witho
	ut ‘doing violence to the original speech’.]It seems that there are three things
	 that people would like me to talk about. On the one hand I thought that the bes
	t thing to talk about here for a club of hackers, was what it was like at the MI
	T in the old days. What made the Artificial Intelligence Lab such a special plac
	e. But people tell me also that since these are totally different people from th
	e ones who were at the conference Monday and Tuesday that I ought to talk about 
	what's going on in the GNU project and that I should talk about why software and
	 information can not be owned, which means three talks in all, and since two of 
	those subjects each took an hour it means we're in for a rather long time. So I 
	had the idea that perhaps I could split it in to three parts, and people could g
	o outside for the parts they are not interested in, and that then when I come to
	 the end of a part I can say it's the end and people can go out and I can send J
	an Rynning out to bring in the other people. (Someone else says: “Janne, han tre
	nger ingen mike” (translation: “Janne, he doesn't need a mike”)). Jan, are you p
	repared to go running out to fetch the other people? Jmr: I am looking for a mic
	rophone, and someone tells me it is inside this locked box. Rms: Now in the old 
	days at the AI lab we would have taken a sledgehammer and cracked it open, and t
	he broken door would be a lesson to whoever had dared to lock up something that 
	people needed to use. Luckily however I used to study Bulgarian singing, so I ha
	ve no trouble managing without a microphone.Anyway, should I set up this system 
	to notify you about the parts of the talk, or do you just like to sit through al
	l of it? (Answer: Yeaaah)When I started programming, it was 1969, and I did it i
	n an IBM laboratory in New York. After that I went to a school with a computer s
	cience department that was probably like most of them. There were some professor
	s that were in charge of what was supposed to be done, and there were people who
	 decided who could use what. There was a shortage of terminals for most people, 
	but a lot of the professors had terminals of their own in their offices, which w
	as wasteful, but typical of their attitude. When I visited the Artificial Intell
	igence lab at MIT I found a spirit that was refreshingly different from that. Fo
	r example: there, the terminals was thought of as belonging to everyone, and pro
	fessors locked them up in their offices on pain of finding their doors broken do
	wn. I was actually shown a cart with a big block of iron on it, that had been us
	ed to break down the door of one professors office, when he had the gall to lock
	 up a terminal. There were very few terminals in those days, there was probably 
	something like five display terminals for the system, so if one of them was lock
	ed up, it was a considerable disaster.In the years that followed I was inspired 
	by that ideas, and many times I would climb over ceilings or underneath floors t
	o unlock rooms that had machines in them that people needed to use, and I would 
	usually leave behind a note explaining to the people that they shouldn't be so s
	elfish as to lock the door. The people who locked the door were basically consid
	ering only themselves. They had a reason of course, there was something they tho
	ught might get stolen and they wanted to lock it up, but they didn't care about 
	the other people they were affecting by locking up other things in the same room
	. Almost every time this happened, once I brought it to their attention, that it
	 was not up to them alone whether that room should be locked, they were able to 
	find a compromise solution: some other place to put the things they were worried
	 about, a desk they could lock, another little room. But the point is that peopl
	e usually don't bother to think about that. They have the idea: “This room is Mi
	ne, I can lock it, to hell with everyone else”, and that is exactly the spirit t
	hat we must teach them not to have.But this spirit of unlocking doors wasn't an 
	isolated thing, it was part of an entire way of life. The hackers at the AI lab 
	were really enthusiastic about writing good programs, and interesting programs. 
	And it was because they were so eager to get more work done, that they wouldn't 
	put up with having the terminals locked up, or lots of other things that people 
	could do to obstruct useful work. The differences between people with high moral
	e who really care about what they're trying to do, and people who think of it as
	 just a job. If it's just a job, who cares if the people who hired you are so st
	upid they make you sit and wait, it's their time, their money but not much gets 
	done in a place like that, and it's no fun to be in a place like that.Another th
	ing that we didn't have at the AI lab was file protection. There was no security
	 at all on the computer. And we very consciously wanted it that way. The hackers
	 who wrote the Incompatible Timesharing System decided that file protection was 
	usually used by a self-styled system manager to get power over everyone else. Th
	ey didn't want anyone to be able to get power over them that way, so they didn't
	 implement that kind of a feature. The result was, that whenever something in th
	e system was broken, you could always fix it. You never had to sit there in frus
	tration because there was NO WAY, because you knew exactly what's wrong, and som
	ebody had decided they didn't trust you to do it. You don't have to give up and 
	go home, waiting for someone to come in in the morning and fix the system when y
	ou know ten times as well as he does what needs to be done.And we didn't let any
	 professors or bosses decide what work was going to be done either, because our 
	job was to improve the system! We talked to the users of course; if you don't do
	 that you can't tell what's needed. But after doing that, we were the ones best 
	able to see what kind of improvements were feasible, and we were always talking 
	to each other about how we'd like to see the system changed, and what sort of ne
	at ideas we'd seen in other systems and might be able to use. So the result is t
	hat we had a smoothly functioning anarchy, and after my experience there, I'm co
	nvinced that that is the best way for people to live.Unfortunately the AI lab in
	 that form was destroyed. For many years we were afraid the AI lab would be dest
	royed by another lab at MIT, the Lab for Computer Science, whose director was a 
	sort of empire builder type, doing everything he could to get himself promoted w
	ithin MIT, and make his organization bigger, and he kept trying to cause the AI 
	lab to be made a part of his lab, and nobody wanted to do things his way because
	 he believed that people should obey orders and things like that.But that danger
	 we managed to defend against, only to be destroyed by something we had never an
	ticipated, and that was commercialism. Around the early 80's the hackers suddenl
	y found that there was now commercial interest in what they were doing. It was p
	ossible to get rich by working at a private company. All that was necessary was 
	to stop sharing their work with the rest of the world and destroy the MIT-AI lab
	, and this is what they did despite all the efforts I could make to prevent them
	.Essentially all the competent programmers except for me, at the AI lab were hir
	ed away, and this caused more than a momentary change, it caused a permanent tra
	nsformation because it broke the continuity of the culture of hackers. New hacke
	rs were always attracted by the old hackers; there were the most fun computers a
	nd the people doing the most interesting things, and also a spirit which was a g
	reat deal of fun to be part of. Once these things were gone, there is nothing to
	 recommend the place to anyone new, so new people stopped arriving. There was no
	-one they could be inspired by, no-one that they could learn those traditions fr
	om. In addition no-one to learn how to do good programming from. With just a bun
	ch of professors and graduate students, who really don't know how to make a prog
	ram work, you can't learn to make good programs work. So the MIT AI lab that I l
	oved is gone and after a couple of years of fighting against the people who did 
	it to try to punish them for it I decided that I should dedicate my self to try 
	to create a new community with that spirit.But one of the problems I had to face
	 was the problem of proprietary software. For example one thing that happened at
	 the lab, after the hackers left, was that the machines and the software that we
	 had developed could no longer be maintained. The software of course worked, and
	 it continued to work if nobody changed it, but the machines did not. The machin
	es would break and there would be no-one who could fix them and eventually they 
	would be thrown out. In the old days, yes we had service contracts for the machi
	nes, but it was essentially a joke. That was a way of getting parts after the ex
	pert hackers from the AI lab fixed the problem. Because if you let the field-ser
	vice person fix it it would take them days, and you didn't want to do that, you 
	wanted it to work. So, the people who knew how to do those things would just go 
	and fix it quickly, and since they were ten times as competent as any field serv
	ice person, they could do a much better job. And then they would have the ruined
	 boards, they would just leave them there and tell the field service person “tak
	e these back and bring us some new ones”.In the real old days our hackers used t
	o modify the machines that came from Digital also. For example, they built pagin
	g-boxes to put on the PDP-10's. Nowadays I think there are some people here [in 
	Stockholm] who do such things too, but it was a pretty unusual thing in those da
	ys. And the really old days, the beginning of the 1960's people used to modify c
	omputers adding all sorts of new instructions and new fancy timesharing features
	, so that the PDP-1 at MIT by the time it was retired in the mid-seventies had s
	omething like twice as many instructions as it had when it was delivered by Digi
	tal in the early sixties, and it had special hardware scheduler assisting featur
	es and strange memory-mapping features making it possible to assign individual h
	ardware devices to particular timesharing jobs and lots of things that I hardly 
	really know about. I think they also built in some kind of extended addressing m
	odes they added index registers and indirect addressing, and they turned it esse
	ntially from a weak machine into a semi-reasonable one.I guess it is one of the 
	disadvantages of VLSI that it's no longer so feasible to add instructions to you
	r machines.The PDP-1 also had a very interesting feature, which is that it was p
	ossible to write interesting programs in very few instructions. Fewer than any o
	ther machine since then. I believe for example that the famous display hack “mun
	ching squares” which made squares that get bigger and break up into lots of smal
	ler squares which gets bigger and break up into smaller squares. That was writte
	n in something like five instructions on the PDP-1. And many other beautiful dis
	play programs could be written in few instructions.So, that was the AI lab. But 
	what was the culture of hackers like aside from their anarchism? In the days of 
	the PDP-1 only one person could use the machine, at the beginning at least. Seve
	ral years later they wrote a timesharing system, and they added lots of hardware
	 for it. But in the beginning you just had to sign up for some time. Now of cour
	se the professors and the students working on official projects would always com
	e in during the day. So, the people who wanted to get lots of time would sign up
	 for time at night when there were less competition, and this created the custom
	 of hackers working at night. Even when there was timesharing it would still be 
	easier to get time, you could get more cycles at night, because there were fewer
	 users. So people who wanted to get lots of work done, would still come in at ni
	ght. But by then it began to be something else because you weren't alone, there 
	were a few other hackers there too, and so it became a social phenomenon. During
	 the daytime if you came in, you could expect to find professors and students wh
	o didn't really love the machine, whereas if during the night you came in you wo
	uld find hackers. Therefore hackers came in at night to be with their culture. A
	nd they developed other traditions such as getting Chinese food at three in the 
	morning. And I remember many sunrises seen from a car coming back from Chinatown
	. It was actually a very beautiful thing to see a sunrise, cause' that's such a 
	calm time of day. It's a wonderful time of day to get ready to go to bed. It's s
	o nice to walk home with the light just brightening and the birds starting to ch
	irp, you can get a real feeling of gentle satisfaction, of tranquility about the
	 work that you have done that night.Another tradition that we began was that of 
	having places to sleep at the lab. Ever since I first was there, there was alway
	s at least one bed at the lab. And I may have done a little bit more living at t
	he lab than most people because every year of two for some reason or other I'd h
	ave no apartment and I would spend a few months living at the lab. And I've alwa
	ys found it very comfortable, as well as nice and cool in the summer. But it was
	 not at all uncommon to find people falling asleep at the lab, again because of 
	their enthusiasm; you stay up as long as you possibly can hacking, because you j
	ust don't want to stop. And then when you're completely exhausted, you climb ove
	r to the nearest soft horizontal surface. A very informal atmosphere.But when th
	e hackers all left the lab this caused a demographic change, because the profess
	ors and the students who didn't really love the machine were just as numerous as
	 before, so they were now the dominant party, and they were very scared. Without
	 hackers to maintain the system, they said, “we're going to have a disaster, we 
	must have commercial software”, and they said “we can expect the company to main
	tain it”. It proved that they were utterly wrong, but that's what they did.That 
	was exactly when a new KL-10 system was supposed to arrive, and the question was
	, would it run the Incompatible Timesharing System or would it run Digital's Twe
	nex system. Once the hackers were gone who probably would have supported using I
	TS, the academic types chose to run the commercial software, and this had severa
	l immediate effects. Some of them weren't actually so immediate but they followe
	d inevitably as anyone who thought about it would see.One thing was that that so
	ftware was much more poorly written, and harder to understand; therefore making 
	it harder for people to make the changes that were in fact needed. Another was, 
	that that software came with security, which had the inevitable effect of causin
	g people to cooperate with each other less. In the old days on ITS it was consid
	ered desirable that everyone could look at any file, change any file, because we
	 had reasons to. I remember one interesting scandal where somebody sent a reques
	t for help in using Macsyma. Macsyma is a symbolic algebra program that was deve
	loped at MIT. He sent to one of the people working on it a request for some help
	, and he got an answer a few hours later from somebody else. He was horrified, h
	e sent a message “so-and-so must be reading your mail, can it be that mail files
	 aren't properly protected on your system?” “Of course, no file is protected on 
	our system. What's the problem? You got your answer sooner; why are you unhappy?
	 Of course we read each other's mail so we can find people like you and help the
	m”. Some people just don't know when they're well off.But of course Twenex not o
	nly has security, and by default turns on security, but it's also designed with 
	the assumption that security is in use. So there are lots of things that are ver
	y easy to do that can cause a lot of damage, and the only thing that would stop 
	you from doing them by accident, is security. On ITS we evolved other means of d
	iscouraging people from doing those things by accident, but on Twenex you didn't
	 have them because they assumed that there was going to be be strict security in
	 effect and only the bosses were going to have the power to do them. So they did
	n't put in any other mechanism to make it hard to do by accident. The result of 
	this is that you can't just take Twenex and turn off the security and have what 
	you'd really like to have, and there were no longer the hackers to make the chan
	ges to put in those other mechanisms, so people were forced to use the security.
	 And about six months after the machine was there they started having some coups
	 d'etat. That is, at first we had the assumption that everyone who worked for th
	e lab was going to have the wheel bit which gave full powers to override all sec
	urity measures, but some days you'd come in some afternoon and find out that the
	 wheel bits of just about everybody had been turned off.When I found out about t
	hose, I overthrew them. The first time, I happened to know the password of one o
	f the people who was included among the elite, so I was able to use that to turn
	 everyone back on. The second time he had changed his password, he had now chang
	ed his sympathies, he was now part of the aristocratic party. So, I had to bring
	 the machine down and use non-timeshared DDT to poke around. I poked around in t
	he monitor for a while, and eventually figured out how to get it to load itself 
	in and let me patch it, so that I could turn off password checking and then I tu
	rned back on a whole bunch of people's wheel bits and posted a system message. I
	 have to explain that the name of this machine was OZ, so I posted a system mess
	age saying: “There was another attempt to seize power. So far the aristocratic f
	orces have been defeated—Radio Free OZ”. Later I discovered that “Radio Free OZ”
	 is one of the things used by Firesign Theater. I didn't know that at the time.B
	ut gradually things got worse and worse, it's just the nature of the way the sys
	tem had been constructed forced people to demand more and more security. Until e
	ventually I was forced to stop using the machine, because I refused to have a pa
	ssword that was secret. Ever since passwords first appeared at the MIT-AI lab I 
	had come to the conclusion that to stand up for my belief, to follow my belief t
	hat there should be no passwords, I should always make sure to have a password t
	hat is as obvious as possible and I should tell everyone what it is. Because I d
	on't believe that it's really desirable to have security on a computer, I should
	n't be willing to help uphold the security regime. On the systems that permit it
	 I use the “empty password”, and on systems where that isn't allowed, or where t
	hat means you can't log in at all from other places, things like that, I use my 
	login name as my password. It's about as obvious as you can get. And when people
	 point out that this way people might be able to log in as me, i say “yes that's
	 the idea, somebody might have a need to get some data from this machine. I want
	 to make sure that they aren't screwed by security”.And an other thing that I al
	ways do is I always turn of all protection on my directory and files, because fr
	om time to time I have useful programs stored there and if there's a bug I want 
	people to be able to fix it.But that machine wasn't designed also to support the
	 phenomenon called “tourism”. Now “tourism” is a very old tradition at the AI la
	b, that went along with our other forms of anarchy, and that was that we'd let o
	utsiders come and use the machine. Now in the days where anybody could walk up t
	o the machine and log in as anything he pleased this was automatic: if you came 
	and visited, you could log in and you could work. Later on we formalized this a 
	little bit, as an accepted tradition specially when the Arpanet began and people
	 started connecting to our machines from all over the country. Now what we'd hop
	e for was that these people would actually learn to program and they would start
	 changing the operating system. If you say this to the system manager anywhere e
	lse he'd be horrified. If you'd suggest that any outsider might use the machine,
	 he'll say “But what if he starts changing our system programs?” But for us, whe
	n an outsider started to change the system programs, that meant he was showing a
	 real interest in becoming a contributing member of the community. We would alwa
	ys encourage them to do this. Starting, of course, by writing new system utiliti
	es, small ones, and we would look over what they had done and correct it, but th
	en they would move on to adding features to existing, large utilities. And these
	 are programs that have existed for ten years or perhaps fifteen years, growing 
	piece by piece as one craftsman after an other added new features.Sort of like c
	ities in France you might say, where you can see the extremely old buildings wit
	h additions made a few hundred years later all the way up to the present. Where 
	in the field of computing, a program that was started in 1965 is essentially tha
	t. So we would always hope for tourists to become system maintainers, and perhap
	s then they would get hired, after they had already begun working on system prog
	rams and shown us that they were capable of doing good work.But the ITS machines
	 had certain other features that helped prevent this from getting out of hand, o
	ne of these was the “spy” feature, where anybody could watch what anyone else wa
	s doing. And of course tourists loved to spy, they think it's such a neat thing,
	 it's a little bit naughty you see, but the result is that if any tourist starts
	 doing anything that causes trouble there's always somebody else watching him. S
	o pretty soon his friends would get very mad because they would know that the co
	ntinued existence of tourism depended on tourists being responsible. So usually 
	there would be somebody who would know who the guy was, and we'd be able to let 
	him leave us alone. And if we couldn't, then what we would do was we would turn 
	off access from certain places completely, for a while, and when we turned it ba
	ck on, he would have gone away and forgotten about us. And so it went on for yea
	rs and years and years.But the Twenex system wasn't designed for this sort of th
	ing, and eventually they wouldn't tolerate me with my password that everybody kn
	ew, tourists always logging in as me two or three at a time, so they started flu
	shing my account. And by that time I was mostly working on other machines anyway
	, so eventually I gave up and stopped ever turning it on again. And that was tha
	t. I haven't logged in on that machine as myself … [At this point RMS is interru
	pted by tremendous applause] … for.But when they first got this Twenex system th
	ey had several changes in mind that they wanted to make. Changes in the way secu
	rity worked. They also wanted to have the machine on both the ARPA network and t
	he MIT-chaos network, and it turns out that they were unable to do this, that th
	ey couldn't get anyone who was sufficiently competent to make such changes. Ther
	e was no longer talent available to do it, and it was to hard to change. That sy
	stem was much harder to understand, because it was to poorly written, and of cou
	rse, Digital wouldn't do these things, so their ideas that a commercial system w
	ould essentially maintain itself, proved to be mistaken. They had just as much n
	eed for system hackers, but they had no longer the means to entice system hacker
	s. And nowadays at MIT there are more people interested in hacking on ITS than t
	here are interested in hacking on Twenex.And the final reason why this is so, is
	 that Twenex can't be shared. Twenex is a proprietary program and you're only al
	lowed to have the sources if you keep them secret in certain nasty ways, and thi
	s gives them a bad flavor. Unless a person is oblivious (which some people in co
	mputers are, there's some people who'll do anything if it's fun for them, and wo
	n't think for a minute whether they're cooperating with anyone else, but you'd h
	ave to be pretty oblivious to not to notice what a sad thing it is to work on a 
	program like that, and that is a further discouragement). And if that isn't enou
	gh there is the fact that every year or so they're going to give you a new relea
	se full of 50 000 additional lines of code all written by monkeys. Because they 
	generally follow the “million monkeys typing, and eventually they'll come up wit
	h something useful” school of system development.It was clear to me from what I 
	saw happening to these proprietary systems that the only way we could have the s
	pirit of the old AI lab was to have a free operating system. To have a system ma
	de up of free software which could be shared with anyone. So that we could invit
	e everyone to join in improving it. And that's what led up to the GNU project. S
	o I guess we've arrived at the second part of the talk.About three and a half ye
	ar ago it was clear to me that I should start developing a free software system.
	 I could see two possible kinds of systems to develop: One: A LISP-machine-like 
	system, essentially a system just like the MIT LISP machine system that had just
	 been developed, except free, and running on general purpose hardware, not on sp
	ecial LISP machines. And the other possibility was a more conventional operating
	 system, and it was clear to me that if I made a conventional operating system, 
	I should make it compatible with Unix, because that would make it easy for peopl
	e all around to switch to it. After a little while, I concluded I should do the 
	latter and the reason was, that I saw that you can't have something really like 
	the LISP machine system on general purpose hardware. The LISP machine system use
	s special hardware plus special writable microcode to gain both good execution s
	peed and robust detection of errors at runtime, specially data-type errors. In o
	rder to make a LISP system run fast enough on ordinary hardware, you have to sta
	rt making assumptions. Assuming that a certain argument is the right type, and t
	hen if it isn't the system just crashes.Of course you can put in explicit checks
	, you can write a robust program if you want, but the fact is that you are going
	 to get things like memory addressing errors when you feed a function an argumen
	t of the wrong type if you did NOT put in things to check for it.So the result i
	s then that you need something running underneath the LISP system to you catch t
	hese errors, and give the user the ability to keep on running, and debug what ha
	ppened to him. Finally I concluded that if I was going to have to have a operati
	ng system at a lower level, I might as well make a good operating-system—that it
	 was a choice between an operating system and the lisp, or just an operating sys
	tem; therefore I should do the operating system first, and I should make it comp
	atible with Unix. Finally when I realized that I could use the most amusing word
	 in the English language as a name for this system, it was clear which choice I 
	had to make. And that word is of course GNU, which stands for “Gnu's Not Unix”. 
	The recursive acronym is a very old tradition among the hacker community around 
	MIT. It started, I believe, with an editor called TINT, which means: “Tint Is No
	t Teco”, and later on it went through names such as “SINE” for “SINE Is Not Emac
	s”, and FINE for “Fine Is Not Emacs”, and EINE for “Eine Is Not Emacs”, and ZWEI
	 for “Zwei Was Eine Initially”, and ultimately now arrives at GNU.I would say th
	at since the time about two and a half years ago when I actually started working
	 on GNU, I've done more than half of the work. When I was getting ready to start
	 working on the project, I first started looking around for what I could find al
	ready available free. I found out about an interesting portable compiler system 
	which was called “the free university compiler kit”, and I thought, with a name 
	like that, perhaps I could have it. So, I sent a message to the person who had d
	eveloped it asking if he would give it to the GNU project, and he said “No, the 
	university might be free, but the software they develop isn't”, but he then said
	 that he wanted to have a Unix compatible system too, and he wanted to write a s
	ort of kernel for it, so why didn't I then write the utilities, and they could b
	oth be distributed with his proprietary compiler, to encourage people to buy tha
	t compiler. And I thought that this was despicable and so I told him that my fir
	st project would be a compiler.I didn't really know much about optimizing compil
	ers at the time, because I'd never worked on one. But I got my hands on a compil
	er, that I was told at the time was free. It was a compiler called PASTEL, which
	 the authors say means “off-color PASCAL”.Pastel was a very complicated language
	 including features such as parametrized types and explicit type parameters and 
	many complicated things. The compiler was of course written in this language, an
	d had many complicated features to optimize the use of these things. For example
	: the type “string” in that language was a parameterized type; you could say “st
	ring(n)” if you wanted a string of a particular length; you could also just say 
	“string”, and the parameter would be determined from the context. Now, strings a
	re very important, and it is necessary for a lot of constructs that use them to 
	run fast, and this means that they had to have a lot of features to detect such 
	things as: when the declared length of a string is an argument that is known to 
	be constant throughout the function, to save to save the value and optimize the 
	code they're going to produce, many complicated things. But I did get to see in 
	this compiler how to do automatic register allocation, and some ideas about how 
	to handle different sorts of machines.Well, since this compiler already compiled
	 PASTEL, what i needed to do was add a front-end for C, which I did, and add a b
	ack-end for the 68000 which I expected to be my first target machine. But I ran 
	into a serious problem. Because the PASTEL language was defined not to require y
	ou to declare something before you used it, the declarations and uses could be i
	n any order, in other words: Pascal's “forward” declaration was obsolete, becaus
	e of this it was necessary to read in an entire program, and keep it in core, an
	d then process it all at once. The result was that the intermediate storage used
	 in the compiler, the size of the memory needed, was proportional to the size of
	 your file. And this also included stack-space, you needed gigantic amounts of s
	tack space, and what I found as a result was: that the 68000 system available to
	 me could not run the compiler. Because it was a horrible version of Unix that g
	ave you a limit of something like 16K words of stack, this despite the existence
	 of six megabytes in the machine, you could only have 16Kw of stack or something
	 like that. And of course to generate its conflict matrix to see which temporary
	 values conflicted, or was alive at the same time as which others, it needed a q
	uadratic matrix of bits, and that for large functions that would get it to hundr
	eds of thousands of bytes. So i managed to debug the first pass of the ten or so
	 passes of the compiler, cross compiled on to that machine, and then found that 
	the second one could never run.While I was thinking about what to do about these
	 problems and wondering whether I should try to fix them or write entirely new c
	ompiler, in a roundabout fashion I began working on GNU Emacs. GNU Emacs is the 
	main distributed portion of the GNU system. It's an extensible text editor a lot
	 like the original emacs which I developed ten years ago, except that this one u
	ses actual LISP as its extension language. The editor itself is implemented in C
	, as is the LISP interpreter, so the LISP interpreter is completely portable, an
	d you don't need a LISP system external to the editor. The editor contains its o
	wn LISP system, and all of the editing commands are written in LISP so that they
	 can provide you with examples to look at for how to write your own editing comm
	ands, and things to start with, so you can change them into the editing commands
	 that you really want.In the summer of that year, about two years ago now, a fri
	end of mine told me that because of his work in early development of Gosling Ema
	cs, he had permission from Gosling in a message he had been sent to distribute h
	is version of that. Gosling originally had set up his Emacs and distributed it f
	ree and gotten many people to help develop it, under the expectation based on Go
	sling's own words in his own manual that he was going to follow the same spirit 
	that I started with the original Emacs. Then he stabbed everyone in the back by 
	putting copyrights on it, making people promise not to redistribute it and then 
	selling it to a software-house. My later dealings with him personally showed tha
	t he was every bit as cowardly and despicable as you would expect from that hist
	ory.But in any case, my friend gave me this program, and my intention was to cha
	nge the editing commands at the top level to make them compatible with the origi
	nal Emacs that I was used to. And to make them handle all the combinations of nu
	merical arguments and so on that one might expect that they would handle and hav
	e all the features that I wanted. But after a little bit of this, I discovered t
	hat the extension language of that editor, which is called MOCKLISP, was not suf
	ficient for the task. I found that that I had to replace it immediately in order
	 to do what I was planning to do. Before I had had the idea of someday perhaps r
	eplacing MOCKLISP with real LISP, but what I found out was that it had do be don
	e first. Now, the reason that MOCKLISP is called MOCK, is that it has no kind of
	 structure datatype: it does not have LISP lists; it does not have any kind of a
	rray. It also does not have LISP symbols, which are objects with names: for any 
	particular name, there is only one object, so that you can type in the name and 
	you always get the same object back. And this tremendously hampers the writing o
	f many kinds of programs, you have to do things by complicated string-manipulati
	on that don't really go that way.So I wrote a LISP interpreter and put it in in 
	place of MOCKLISP and in the process I found that I had to rewrite many of the e
	ditor's internal data structures because I wanted them to be LISP objects. I wan
	ted the interface between the LISP and the editor to be clean, which means that 
	objects such as editor buffers, sub-processes, windows and buffer-positions, all
	 have to be LISP objects, so that the editor primitives that work on them are ac
	tually callable as LISP functions with LISP data. This meant that I had to redes
	ign the data formats of all those objects and rewrite all the functions that wor
	ked on them, and the result was that after about six months I had rewritten just
	 about everything in the editor.In addition, because it is so hard to write thin
	gs in MOCKLISP, all the things that had been written in MOCKLISP were very uncle
	an and by rewriting them to take advantage of the power of real LISP, I could ma
	ke them much more powerful and much simpler and much faster. So I did that, and 
	the result was that when I started distributing this program only a small fracti
	on remained from what I had received.At this point, the company that Gosling thi
	nks he sold the program to challenged my friend's right to distribute it, and th
	e message was on backup tapes, so he couldn't find it. And Gosling denied having
	 given him permission. And then a strange thing happened. He was negotiating wit
	h this company, and it seemed that the company mainly was concerned with not hav
	ing anything distributed that resembled what they were distributing. See, he was
	 still distributing, and the company where he worked, which is Megatest, was sti
	ll distributing the same thing he had given me, which really was an old version 
	of Gosling Emacs with his changes, and so he was going to make an agreement with
	 them where he would stop distributing that, and would switch to using GNU Emacs
	, and they would then acknowledge that he really had the permission after all, a
	nd then supposedly everyone would be happy. And this company was talking to me a
	bout wanting to distribute GNU Emacs, free of course, but also sell various sort
	s of supporting assistance, and they wanted to hire me to help do the work. So i
	t's sort of strange that they then changed their mind and refused to sign that a
	greement, and put up a message on the network saying that I wasn't allowed to di
	stribute the program. They didn't actually say that they would do anything, they
	 just said that it wasn't clear whether they might ever someday do something. An
	d this was enough to scare people so that no one would use it any more, which is
	 a sad thing.(Sometimes I think that perhaps one of the best things I could do w
	ith my life is: find a gigantic pile of proprietary software that was a trade se
	cret, and start handing out copies on a street corner so it wouldn't be a trade 
	secret any more, and perhaps that would be a much more efficient way for me to g
	ive people new free software than actually writing it myself; but everyone is to
	o cowardly to even take it.)So I was forced to rewrite all the rest that remaine
	d, and I did that, it took me about a week and a half. So they won a tremendous 
	victory. And I certainly wouldn't ever cooperate with them in any fashion after 
	that.Then after GNU Emacs was reasonably stable, which took all in all about a y
	ear and a half, I started getting back to other parts of the system. I developed
	 a debugger which I called GDB which is a symbolic debugger for C code, which re
	cently entered distribution. Now this debugger is to a large extent in the spiri
	t of DBX, which is a debugger that comes with Berkeley Unix. Commands consist of
	 a word that says what you want to do, followed by arguments. In this debugger, 
	commands can all be abbreviated, and the common commands have single character a
	bbreviations, but any unique abbreviation is always allowed. There are extensibl
	e HELP facilities, you can type HELP followed by any command or even subcommands
	, and get a lengthy description of how to use that command. Of course you can ty
	pe any expression in C, and it will print the value.You can also do some things 
	that are not usual in symbolic C debuggers, for example: You can refer to any C 
	datatype at any memory address, either to examine the value, or to assign the va
	lue. So for example if you want to store a floating point value in a word at a c
	ertain address, you just say: “Give me the object of type FLOAT or DOUBLE at thi
	s address” and then assign that. Another thing you can do is to examine all the 
	values that have been examined in the past. Every value examined gets put on the
	 “value history”. You can refer to any element in the history by its numerical p
	osition, or you can easily refer to the last element with just dollar-sign. And 
	this makes it much easier to trace list structure. If you have any kind of C str
	ucture that contains a pointer to another one, you can do something like “PRINT 
	*$.next”, which says: “Get the next field out of the last thing you showed me, a
	nd then display the structure that points at”. And you can repeat that command, 
	and each time you'll see then next structure in the list. Whereas in every other
	 C debugger that I've seen the only way to do that is to type a longer command e
	ach time. And when this is combined with the feature that just typing carriage-r
	eturn repeats the last command you issued, it becomes very convenient. Just type
	 carriage-return for each element in the list you want to see.There are also exp
	licitly settable variables in the debugger, any number of them. You say dollar-s
	ign followed by a name, and that is a variable. You can assign these variables v
	alues of any C datatype and then you can examine them later. Among the things th
	at these are useful for are: If there's a particular value that you're going to 
	examine, and you know you are going to refer to it a lot, then rather than remem
	ber its number in the history you might give it a name. You might also find use 
	for them when you set conditional breakpoints. Conditional breakpoints are a fea
	ture in many symbolic debuggers, you say “stop when you get to this point in the
	 program, but only if a certain expression is true”. The variables in the debugg
	er allow you to compare a variable in the program with a previous value of that 
	variable that you saved in a debugger variable. Another thing that they can be u
	sed for is for counting, because after all, assignments are expressions in C, th
	erefore you can do “$foo+=5” to increment the value of “$foo” by five, or just “
	$foo++” you can do. You can even do this in a conditional breakpoint, so that's 
	a cheap way of having it break the tenth time the breakpoint is hit, you can do 
	“$foo--==0”. Does everyone follow that? Decrement foo and if it's zero now, brea
	k. And then you set $foo to the number of times you want it to skip, and you let
	 it go. You can also use that to examine elements of an array. Suppose you have 
	an array of pointers, you can then do:PRINT X[$foo++]But first you doSET $foo=0O
	kay, when you do that [points at the “Print” expression], you get the zeroth ele
	ment of X, and then you do it again and it gets the first element, and suppose t
	hese are pointers to structures, then you probably put an asterisk there [before
	 the X in the PRINT expression] and each time it prints the next structure point
	ed to by the element of the array. And of course you can repeat this command by 
	typing carriage-return. If a single thing to repeat is not enough, you can creat
	e a user-defined-command. You can say “Define Mumble”, and then you give some li
	nes of commands and then you say “end”. And now there is defined a “Mumble” comm
	and which will execute those lines. And it's very useful to put these definition
	s in a command file. You can have a command file in each directory, that will be
	 loaded automatically when you start the debugger with that as your working dire
	ctory. So for each program you can define a set of user defined commands to acce
	ss the data structures of that program in a useful way. You can even provide doc
	umentation for your user-defined commands, so that they get handled by the “help
	” features just like the built-in commands.One other unusual thing in this debug
	ger, is the ability to discard frames from the stack. Because I believe it's imp
	ortant not just to be able to examine what's happening in the program you're deb
	ugging, but also to change it in any way conceivable. So that after you've found
	 one problem and you know what's wrong, you can fix things up as if that code we
	re correct and find the next bug without having to recompile your program first.
	 This means not only being able to change the data areas in you program flexibly
	, but also being able to change the flow of control. In this debugger you can ch
	ange the flow of control very directly by saying:SET $PC=<some number>So you can
	 set the program counter. You can also set the stack pointer, or you can saySET 
	$SP+=<something>If you want to increment the stack pointer a certain amount. But
	 in addition you can also tell it to start at a particular line in the program, 
	you can set the program counter to a particular source line. But what if you fin
	d that you called a function by mistake and you didn't really want to call that 
	function at all? Say, that function is so screwed up that what you really want t
	o do is get back out of it and do by hand what that function should have done. F
	or that you can use the “RETURN” command. You select a stack frame and you say “
	RETURN”, and it causes that stack-frame, and all the ones within it, to be disca
	rded as if that function were returning right now, and you can also specify the 
	value it should return. This does not continue execution; it pretends that retur
	n happened and then stops the program again, so you can continue changing other 
	things.And with all these things put together you thus have pretty good control 
	over what's going on in a program.In addition one slightly amusing thing: C has 
	string constants, what happens if you use a string constant in an expression tha
	t you're computing in the debugger? It has to create a string in the program you
	 were debugging. Well it does. It sets up a call to MALLOC in that debugged prog
	ram, lets MALLOC run, and then gets control back. Thus it invisibly finds a plac
	e to put the string constant.Eventually when this debugger is running on the rea
	l GNU system, I intend to put in facilities in the debugger to examine all of th
	e internal status of the process that is running underneath it. For example to e
	xamine the status of the memory map, which pages exist, which are readable, whic
	h are writable, and to examine the inferior program's terminal status. There alr
	eady is a bit of a command; this debugger, unlike the debuggers on Unix, keeps t
	he terminal status completely separate for the debugger and the program you're d
	ebugging, so that it works with programs that run in raw mode, it works with pro
	grams that do interrupt driven input, and there's also a command that enables yo
	u to find out something about the terminal settings at the program you're debugg
	ing is actually using. I believe that in general a debugger should allow you to 
	find out everything that's going on in the inferior process.There are two other 
	main parts of the GNU system that already exist. One is the new C compiler, and 
	one is the TRIX kernel.The new C compiler is something that I've written this ye
	ar since last spring. I finally decided that I'd have to throw out PASTEL. This 
	C compiler uses some ideas taken from PASTEL, and some ideas taken from the Univ
	ersity of Arizona Portable Optimizer. Their interesting idea was to handle many 
	different kinds of machines by generating simple instructions, and then combinin
	g several simple instructions into a complicated instruction when the target mac
	hine permits it. In order to do this uniformly, they represent the instructions 
	in algebraic notation. For example, an ADD instruction might be represented like
	 this:  r[3]=r[2]+4This would be a representation inside their compiler for inst
	ruction to take the contents of register two, add four and store it in register 
	three. In this fashion you can represent any possible instruction for any machin
	e. So they actually did represent all the instructions this way and then when it
	 came time to try to combine them, they would do this by substituting one expres
	sion into another, making a more complicated algebraic expression for the combin
	ed instruction.Sometimes depending on whether the result of the first instructio
	n had any further use, it might be necessary to make a combined instruction with
	 two assignment operators. One for this value [pointing at ???]and another one w
	ith this value [pointing at ???] substituted in it with what came from the secon
	d instruction. But if this value was only used that once, you could eliminate it
	 after substituting for it; there'd be no need to compute it any more. So it's a
	ctually somewhat complicated doing the substitution correctly checking that the 
	intervening instructions don't change any of these values and other such things.
	 When you support such things as auto-increment and auto-decrement addressing, w
	hich I do now, you also have to do various checks for those to check for situati
	ons where what you're doing is not value preserving.But after checking all those
	 things, then you take the substituted combined expression and put it through a 
	pattern matcher, which recognizes all the valid instructions of your chosen targ
	et machine. And if it's recognized, then you replace those two instructions with
	 the combined one, otherwise you leave them alone. And their technique is to com
	bine two or three instructions related by data flow in this way.In the Arizona c
	ompiler, they actually represent things as text strings like this, and their com
	piler is horribly slow. First I had some idea of just using their compiler and m
	aking changes in it, but it was clear to me I had to rewrite it entirely to get 
	the speed I wanted, so I have rewritten it to use list structure representations
	 for all these expressions. Things like this:     (set (reg 2)          (+ (reg 
	2)             (int 4)))This looks like Lisp, but the semantics of these are not
	 quite LISP, because each symbol here is one recognized specially. There's a par
	ticular fixed set of these symbols that is defined, all the ones you need. And e
	ach one has a particular pattern of types of arguments, for example: “reg” alway
	s has an integer, because registers are numbered, but “+” takes two subexpressio
	ns, and so on. And with each of these expressions is also a data type which says
	 essentially whether it's fixed or floating and how many bytes long it is. It co
	uld be extended to handle other things too if you needed to.And the way I do aut
	omatic register allocation is that when I initially generate this code, and when
	 I do the combination and all those things, for every variable that conceivably 
	go into a register, I allocate what I call a pseudo register number, which is a 
	number starting at sixteen or whatever is too high to be a real register for you
	r target machine. So the real registers are numbered zero to fifteen or whatever
	 and above that comes pseudo registers. And then one of the last parts of the co
	mpiler consists of going through and changing all the pseudo registers to real r
	egisters. Again it makes a conflict graph, it sees which pseudo registers are al
	ive at the same point and they of course can't go in the same real register, and
	 then it tries packing pseudo registers into real registers as much as it can, o
	rdering them by priority of how important they are.And finally it then has to co
	rrect the code for various problems, such as happen when there were pseudo regis
	ters that don't fit in the real registers, that had to be put into stack slots i
	nstead. When that happens on certain machines, some of the instructions may beco
	me invalid. For example on the 68000 you can add a register into memory and you 
	can add memory into register, but you can't add one memory location into another
	. So if you have an ADD instruction, and you're headed for a 68000 and both of t
	he things end up in memory, it's not valid. So this final pass goes through and 
	copies things into registers and out of registers as needed to correct those pro
	blems.Problems can also arise with index registers. If you're trying to index by
	 something, then most of the time that code will become invalid if the index qua
	ntity is in memory, except in a few cases on some machines where you can it with
	 indirect addressing. In the cases when you're doing auto-increment on an index 
	register you may have to copy the value into a register, do the instruction, and
	 then copy the incremented value back to the memory slot where it really lives.T
	here's got room for a lot of hair, and I've not finished implementing all the ha
	ir needed to make really fully efficient.This compiler currently works by having
	 a parser which turns C code into effectively a syntax tree annotated with C dat
	atype information. Then another pass which looks at that tree and generates code
	 like this [LISP like code]. Then several optimization passes. One to handle thi
	ngs like jumps across jumps, jumps to jumps, jumps to .+1, all of which can be i
	mmediately simplified. Then a common subexpression recognizer, then finding basi
	c blocks, and performing dataflow-analysis, so that it can tell for each instruc
	tion which values are used in that instruction and never used afterward. And als
	o linking each instruction to the places where the values it uses were generated
	, so if I have one instruction which generates pseudo register R[28], and then a
	nother instruction later which uses R[28] and it's the first place to use R[28],
	 I make the second one point back to the first one, and this pointer is used to 
	control the attempts to combine the instructions. You don't combine adjacent ins
	tructions, you combine an instruction that uses a value with the instruction tha
	t produced that value. Even if there are other instructions in between, they don
	't matter for this, you just have to check them to make sure they don't do anyth
	ing to interfere. Then after the combiner comes the dynamic register allocator, 
	and finally something to convert it into assembly code.In the Arizona compiler t
	he instruction recognizer was generated with LEX. Your machine description was s
	imply a LEX program that LEX would turn into a C function to recognize valid ins
	tructions as strings. What I have is instead a special purpose decision tree tha
	t's generated from a machine description written in this syntax as if it were LI
	SP. And this recognizer is used as a subroutine for many different parts of the 
	compiler.Currently this compiler runs about as fast as PCC. It runs noticeably f
	aster if you tell it not to do the hairy register allocation, in which case it a
	llocates registers the same way as PCC does. In its super hairy mode it does a m
	uch better job of allocating registers than PCC, and I observe that for the VAX 
	it generates the best code I've seen from any C compiler on the VAX.For the 6800
	0 the code is still not ideal. I can see places where early stages do things tha
	t are not the best, because it can't fully look ahead. It has a choice in an ear
	ly stage, and it does the thing that it thinks is going to be best, but really i
	f it did the other one, a later stage is actually smart enough to do something e
	ven better. But the early stage doesn't know what the later stage is going to do
	, so I have more work to do on some of these things.Sometimes this causes it to 
	free up registers unnecessarily. Because when things wind up in memory and it ne
	eds to copy them into registers, it needs to get registers to copy them into. Th
	is means taking registers that it has already allocated to, and kicking those te
	mporary quantities out to stack slots. Of course this may invalidate more instru
	ctions now that those things are in memory, not registers, so it has to check ag
	ain and again. Sometimes it thinks it has to copy things to registers and really
	 it isn't going to have to, so it may free up too many things and thus not use a
	ll the registers that it could.(Question: Do you have a code generator for 32000
	?) Not yet, but again, it's not a code generator it's just a machine description
	 that you need. A list of all the machine instructions described in this [LISP l
	ike] form. So in fact aside from the work of implementing the idea of constraint
	s on which arguments can be in registers and which kind of registers, which is s
	omething which was needed for the 68000 and was not needed for the VAX, the work
	 of porting this compiler from the VAX to the 68000 just took a few days. So it'
	s very easy to port.The compiler currently generates assembler code and it can g
	enerate debugging information either in the format that DBX wants, or in the spe
	cial internal format of GDB. I'd say the only work needed on this compiler is in
	 three areas. One: I have to add a “profiling” feature, like the one that the Un
	ix compilers have. Two: I have to make these register allocation things smarter,
	 so that I can stop seeing stupid things appearing in the output. And three: The
	re are various bugs, things that doesn't handle correctly yet, although it has c
	ompiled itself correctly. I expect this will just take a few months, and then I 
	will release the compiler.The other sizable part of the system that exist, is th
	e kernel. (Question: A pause?) Ah, yeah I guess we've forgotten about breaks. Wh
	y don't I finish talking about the kernel, which should only take about five min
	utes, and then we can take a break.Now, for the kernel I am planning to use a sy
	stem called TRIX (it doesn't stand for anything that I know of) which was develo
	ped as a research project at MIT. This system is based on Remote Procedure Call.
	 Thus programs are called domains. Each domain is a address space and various ca
	pabilities, and a capability is none other than the ability to call a domain. An
	y domain can create “capability ports” to call it, and then it can pass these po
	rts to other domains, and there is no difference between calling the system and 
	calling another user domain. In fact you can't tell which you have. Thus it is v
	ery easy to have devices implemented by other user programs. A file system could
	 be implemented by a user program, transparently. It's also transparent to commu
	nicate across networks. You think that you're directly calling another domain, b
	ut really you're calling the network server domain. It takes the information tha
	t you gave in the call, and passes this over the network to another server progr
	am which then calls the domain that you're trying to talk to. But you and that o
	ther domain see this as happening invisibly.The TRIX kernel runs, and it has a c
	ertain limited amount of Unix compatibility, but it needs a lot more. Currently 
	it has a file system that uses the same structure on disk as the ancient Unix fi
	le system does. This made it easier to debug the thing, because they could set u
	p the files with Unix, and then they could run TRIX, but that file system doesn'
	t have any of the features that I believe are necessary.Features that I believe 
	must be added include: Version numbers, undeletion, information on when and how 
	and where the file was backed up on tape, atomic superseding of files. I believe
	 that it is good that in Unix when a file is being written, you can already look
	 at what's going there, so for example, you can use “tail” to see how far the th
	ing got, that's very nice. And if the program dies, having partly written the fi
	le, you can see what it produced. These things are all good, but, that partly wr
	itten output should not ever be taken for the complete output that you expected 
	to have eventually. The previous version of that should continue to be visible a
	nd used by everyone who tries to use it, until the new version is completely and
	 correctly made. This means that the new version should be visible in the file s
	ystem but not under the name it is supposed to have. It should get renamed when 
	it's finished. Which is by the way what happens in ITS, although there each user
	 program has to do this explicitly. For Unix compatibility with the user program
	s, it has to happen invisibly.I have a weird hairy scheme to try to make version
	 numbers fit with the existing Unix user programs. And this is the idea that you
	 specify a file name leaving the version number implicit, if you just specify th
	e name in the ordinary way. But if you wish to specify a name exactly, either be
	cause you want to state explicitly what version to use, or because you don't wan
	t versions at all, you put a point at the end of it. Thus if you give the filena
	me “FOO” it means “Search the versions that exists for FOO and take the latest o
	ne”. But if you say “FOO.” it means “use exactly the name FOO and none other”. I
	f you say “FOO.3.” it says “use exactly the name FOO.3 ” which of course is vers
	ion three of FOO and none other. On output, if you just say “FOO”, it will event
	ually create a new version of “FOO”, but if you say “FOO.” it will write a file 
	named exactly “FOO”.Now there's some challenges involved in working out all the 
	details in this, and seeing whether there are any lingering problems, whether so
	me Unix software actually breaks despite feeding them names with points in them 
	and so on, to try to make it get the same behavior.I would expect that when you 
	open a file for output whose name ends in a point, you should actually open that
	 name right away, so you get the so you get the same Unix behavior, the partiall
	y written output is immediately visible, whereas when you output a name that doe
	sn't end in a point, the new version should appear when you close it, and only i
	f you close it explicitly. If it gets closed because the job dies, or because th
	e system crashes or anything like that, it should be under a different name.And 
	this idea can be connected up to “star matching”, by saying that a name that doe
	sn't end in a point is matched against all the names without their version numbe
	rs, so if a certain directory has files like this:  foo.1 foo.2 bar.8If I say “*
	”, that's equivalent to  foo barbecause it takes all the names and gets rid of t
	heir versions, and takes all the distinct ones. But if I say “*.” then it takes 
	all the exact names, puts a point after each one, and matches against them. So t
	his gives me all the names for all the individual versions that exist. And simil
	ar, you can see the difference between “*.c” and “*.c.” this [the first] would g
	ive you essentially versionless references to all the “.c” files, whereas this [
	the second] will give you all the versions … well this actually wouldn't, you'd 
	have to say “*.c.*.”. I haven't worked out the details here.Another thing, that 
	isn't a user visible feature and is certainly compatible to put in, is failsafen
	ess in the file system. Namely, by writing all the information on disk in the pr
	oper order, arranging that you can press “halt” at any time without ever corrupt
	ing thereby the file system on disk. It is so well known how to do this, I can't
	 imagine why anyone would neglect it. Another idea is further redundant informat
	ion. I'm not sure whether I'll do this or not, but I have ideas for how to store
	 in each file all of its names, and thus make it possible if any directory on di
	sk is lost, to reconstruct it from the rest of the contents of the disk.Also I t
	hink I know how to make it possible to atomically update any portion of a file. 
	Thus if you want to replace a certain subrange of a file with new data in such a
	 fashion that any attempt to read the file will either see only the old data, or
	 only the new data. I believe I can do that, without any locking even.For networ
	k support, I intend eventually to implement TCP/IP for this system. I also think
	 it's possible to use KERMIT to get something effectively equivalent to UUCP.A s
	hell I believe has already been written. It has two modes, one imitating the BOU
	RNE shell, and one imitating the C-shell in the same program. I have not receive
	d a copy of it yet, and I don't know how much work I'll have to do on it. Also m
	any other utilities exists. A MAKE exists, LS, there's a YACC replacement called
	 BISON which is being distributed. Something pretty close to a LEX exists, but i
	t's not totally compatible, it needs some work. And, in general what remains to 
	be done is much less that what's been done, but we still need lots of people to 
	help out.People always ask me “When is it going to be finished?” Of course I can
	't know when it's going to be finished, but that's the wrong question to ask me.
	 If you were planning to pay for it, it would make sense for you to want to know
	 exactly what are you going to get and when. But since you're not going to pay f
	or it, the right question for you to ask is “how can you help make it get finish
	ed sooner?” I have a list of projects, it is on a file at MIT, and people who ar
	e interested in helping could send me mail at this Internet address, and I will 
	send back a list of projects. (I wonder if this is will work (looking at the cha
	lk)). Is this readable? This is “RMS@GNU.ORG” (just follow the bouncing ball.) A
	nd now let's take a break, and after the break, I will say some really controver
	sial things. So don't leave now. If you leave now, you're going to miss the real
	 experience.[Here we had a 15 min. break]I've been asked to announce how you can
	 get copies of GNU software. Well, one way of course is if you know a friend who
	 has a copy, you can copy it, but if you don't know a friend who has a copy, and
	 you're not on the Internet, you can't FTP it, then you can always order a distr
	ibution tape, and send some money to the Free Software Foundation. Of course fre
	e programs is not the same thing as free distribution. I'll explain this in deta
	il later.Here I have an EMACS manual, of the nicely printed variety. It has been
	 phototypeset and then offset printed. Although you can also print it yourself f
	rom the sources that come in the EMACS distribution, you can get these copies fr
	om the Free Software Foundation. You can come afterwards and look at this and al
	so this contains an order for you might copy some information from, and this [fr
	ont] picture has also sometimes been enjoyed. This [pointing at a figure being c
	hased by RMS riding a gnu] is a scared software hoarder, I'll be talking about h
	im in a moment.Software is a relatively new phenomenon. People started distribut
	ing software perhaps thirty years ago. It was only about twenty years ago that s
	omeone had the idea of making a business about it. It was an area with no tradit
	ion about how people did things, or what rights anybody had. And there were seve
	ral ideas for what other areas of life you might bring traditions from by analog
	y.One analogy that is liked by a lot of professors in Europe, is that between pr
	ograms and mathematics. A program is sort of a large formula. Now, traditionally
	 nobody can own a mathematical formula. Anybody can copy them and use them.The a
	nalogy that's most meaningful to ordinary people is with recipes. If you think a
	bout it, the thing that you have in ordinary life that's most like program is a 
	recipe, it's instructions for doing something. The differences come because a re
	cipe is followed by a person, not by a machine automatically. It's true there's 
	no difference between source code and object code for a recipe, but it's still t
	he closest thing. And no-one is allowed to own a recipe.But the analogy that was
	 chosen was the analogy with books, which have copyright. And why was this choic
	e made? Because the people that had the most to gain from making that particular
	 choice were allowed to make the decision. The people who wrote the programs, no
	t the people who used the programs, were allowed to decide, and they decided in 
	a completely selfish fashion, and as a result they've turned the field of progra
	mming into an ugly one.When I entered the field, when I started working at MIT i
	n 1971, the idea that programs we developed might not be shared was not even dis
	cussed. And the same was Stanford and CMU, and everyone, and even Digital. The o
	perating system from Digital at that time was free. And every so often I got pie
	ces of program from Digital system such as a PDP-11 cross assembler, and I porte
	d it to run on ITS, and added lots of features. It was no copyright on that prog
	ram.It was only in the late seventies that this began to change. I was extremely
	 impressed by the sharing spirit that we had. We were doing something that we ho
	ped was useful and were happy if people could use it. So when I developed the fi
	rst EMACS, and people wanted to start use it outside of MIT, I said that it belo
	ngs to the EMACS “Commune”, that in order to use EMACS you had to be a member of
	 the commune, and that meant that you had the responsibility to contribute all t
	he improvements that you made. All the improvements to the original EMACS had to
	 be sent back to me so that I could incorporate them into newer versions of EMAC
	S, so that everyone in the community could benefit from them.But this started to
	 be destroyed when SCRIBE was developed at CMU, and then was sold to a company. 
	This was very disturbing to a lot of us at many universities, because we saw tha
	t this was a temptation placed in front of everyone, that it was so profitable t
	o be uncooperative and those of us who still believed in cooperation had no weap
	on to try to compel people to cooperate with us. Clearly, one after another, peo
	ple would defect and stop cooperating with the rest of society, until only those
	 of us with very strong consciences would still cooperate. And that's what happe
	ned.The field of programming has now become an ugly one, where everyone cynicall
	y thinks about how much money he is going to get by not being nice to the other 
	people in the field, and to the users.I want to establish that the practice of o
	wning software is both materially wasteful, spiritually harmful to society and e
	vil. All these three things being interrelated. It's spiritually harmful because
	 it involves every member of society who comes in contact with computers in a pr
	actice that is obviously materially wasteful to other people. And every time you
	 do something for your own good, which you know is hurting other people more tha
	t it helps you, you have to become cynical in order to support such a thing in y
	our mind. And it's evil because it is deliberately wasting the work done in soci
	ety and causing social decay.First I want to explain the kinds of harm that are 
	done by attempts to own software and other information that's generally useful, 
	then I'll go on to rebut the arguments made to support that practice, and then I
	 want to talk about how to fight that phenomenon, and how I'm fighting it.The id
	ea of owning information is harmful in three different levels. Materially harmfu
	l on three different levels, and each kind of material harm has a corresponding 
	spiritual harm.The first level is just that it discourages the use of the progra
	m, it causes fewer people to use the program, but in fact it takes no less work 
	to make a program for fewer people to use. When you have a price on the use of a
	 program this is an incentive, that's the word these software hoarders love to u
	se, the price is an incentive for people not to use the program, and this is a w
	aste. If for example only half as many people use the program because it has a p
	rice on it, the program has been half wasted. The same amount of work has produc
	ed only half as much wealth.Now in fact, you don't have to do anything special t
	o cause a program to get around to all the people who want to use it, because th
	ey can copy it themselves perfectly well, and it will get to everyone. All you h
	ave to do after you've written the program is to sit back and let people do what
	 they want to do. But that's not what happens; instead somebody deliberately tri
	es to obstruct the sharing of the program, and in fact, he doesn't just try to o
	bstruct it, he tries to pressure other people into helping. Whenever a user sign
	s a nondisclosure agreement he has essentially sold out his fellow users. Instea
	d of following the golden rule and saying, “I like this program, my neighbor wou
	ld like the program, I want us both to have it”, instead he said, “Yeah, give it
	 to me. To hell with my neighbor! I'll help you keep it away from my neighbor, j
	ust give it to me!”, and that spirit is what does the spiritual harm. That attit
	ude of saying, “To hell with my neighbors, give ME a copy”.After I ran into peop
	le saying they wouldn't let me have copies of something, because they had signed
	 some secrecy agreement, then when somebody asked me to sign a thing like that I
	 knew it was wrong. I couldn't do to somebody else the thing that had made me so
	 angry when it was done to me.But this is just one of the levels of harm. The se
	cond level of harm comes when people want to change the program, because no prog
	ram is really right for all the people who would like to use it. Just as people 
	like to vary recipes, putting in less salt say, or maybe they like to add some g
	reen peppers, so people also need to change programs in order to get the effects
	 that they need.Now, the software owners don't really care whether people can ch
	ange the program or not, but it's useful for their ends to prevent people. Gener
	ally when software is proprietary you can't get the sources, you can't change it
	, and this causes a lot of wasted work by programmers, as well as a lot of frust
	ration by users. For example: I had a friend who told me how she worked for many
	 months at a bank where she was a programmer, writing a new program. Now, there 
	was a commercially available program that was almost right, but it was just not 
	quite the thing they needed, and in fact as it was it was useless for them. The 
	amount of change it would have taken to make it do what they needed was probably
	 small, but because the sources of that program were not available, that was imp
	ossible. She had to start over from scratch and waste a lot of work. And we can 
	only speculate about what fraction of all the programmers in the world are wasti
	ng their time in this fashion.And then there is also the situation where a progr
	am is adequate make do, but it's uncomfortable. For example: The first time we h
	ad a graphics printer at MIT, we wrote the software ourselves, and we put in lot
	s of nice features, for example it would send you a message when your job had fi
	nished printing, and it would send you a message if the printer ran out of paper
	 and you had a job in the queue, and lots of other things that were what we want
	ed. We then got a much nicer graphic printer, one of the first laser printers, b
	ut then the software was supplied by Xerox, and we couldn't change it. They woul
	dn't put in these features, and we couldn't, so we had to make do with things th
	at “half worked”. And it was very frustrating to know that we were ready, willin
	g and able to fix it, but weren't permitted. We were sabotaged.And then there ar
	e all the people who use computers and say that the computers are a mystery to t
	hem, they don't know they work. Well how can they possibly know? They can't read
	 the programs they're using. The only way people learn how programs should be wr
	itten, or how programs do what they do, is by reading the source code.So I could
	 only wonder whether the idea of the user who just thinks of the computer as a t
	ool is not actually a self-fulfilling prophecy, a result of the practice of keep
	ing source code secret.Now the spiritual harm that goes with this kind of materi
	al harm, is in the spirit of self-sufficiency. When a person spends a lot of tim
	e using a computer system, the configuration of that computer system becomes the
	 city that he lives in. Just as the way our houses and furniture are laid out, d
	etermines what it's like for us to live among them, so that the computer system 
	that we use, and if we can't change the computer system that we use to suit us, 
	then our lives are really under the control of others. And a person who sees thi
	s becomes in a certain way demoralized: “It's no use trying to change those thin
	gs, they're always going to be bad. No point even hassling it. I'll just put in 
	my time and … when it's over I'll go away and try not to think about it any more
	”. That kind of spirit, that unenthusiasm is what results from not being permitt
	ed to make things better when you have feelings of public spirit.The third level
	 of harm is in the interaction between software developers themselves. Because a
	ny field of knowledge advance most when people can build on the work of others, 
	but ownership of information is explicitly designed to prevent anyone else to do
	ing that. If people could build on other people's work, then the ownership would
	 become unclear, so they make sure each new entry to the field has to start from
	 the beginning, and thus they greatly slow down the advance of the field.So we c
	an see: How many spreadsheet systems were made all by different companies, all w
	ithout any benefit of understanding how it was done before? Yes it's true, the f
	irst spreadsheet written wasn't perfect. It probably only ran on certain kinds o
	f computers, and it didn't do some things in the best possible way. So there wer
	e various reasons why certain people would want to rewrite parts of it. But if t
	hey had only to rewrite the parts that they really wanted to improve, that would
	 have made for a lot less work. You may see how to make one aspect of a system b
	etter, you may not see how to make another aspect of the same system any better,
	 in fact you might have a great deal of trouble doing it as well. Now if you cou
	ld take the part that you like and redo only the part that you have an inspirati
	on for, you could have a system that's better in all ways, with much less work t
	han it now takes to write a completely new system. And we all know that a system
	 can often benefit from being completely rewritten, but that's only if you can r
	ead the old one first.Thus, the people in the programming field have evolved a w
	ay of wasting a lot of their time and thus making apparently a need for more pro
	grammers than we really need. Why is there a programmer shortage? Because with i
	ntellectual property programmers have arranged to waste half the work they do, s
	o we seem to need twice as many programmers. And so, when people point to the sy
	stem of intellectual property and say “look at the large employment statistics, 
	look at how big this industry is” what that really proves is that people are was
	ting a lot of money and time. If they talk about looking for ways to improve pro
	grammer productivity, they're happy to do this if it involves superior tools, bu
	t to improve programmer productivity by getting rid of the explicit things that 
	is done to reduce programmer productivity, that they're against. Because that wo
	uld reduce the number of programmers employed. There's something a little bit sc
	hizophrenic there.And the spiritual harm that corresponds to this level of mater
	ial harm is to the spirit of scientific cooperation, which used to be so strong 
	that scientists even in countries that were at war would continue cooperating, b
	ecause they knew that what they were doing had nothing to do with the war, it wa
	s just for the long term benefit of humanity. Nowadays, people don't care about 
	the long term benefit of humanity any more.To get an idea of what it's like to o
	bstruct the use of a program, let's imagine that we had a sandwich, that you cou
	ld eat, and it wouldn't be consumed. You could eat it, and another person could 
	eat it, the same sandwich, any number of times, and it would always remain just 
	as nourishing as originally.The best thing to do, the thing that we ought to do 
	with this sandwich is carry it around to the places where there are hungry peopl
	e; bringing it to as many mouths as possible, so that it feeds as many people as
	 possible. By all means, we should not have a price to eat from this sandwich, b
	ecause then people would not afford to eat it, and it would be wasted.The progra
	m is like this sandwich, but even more so because it can be in many different pl
	aces at once being eaten, used by different people one after the other. It is as
	 if this sandwich was enough to feed everyone, everywhere, forever, and that wer
	e not allowed to happen, because someone believed he should own it.Now, the peop
	le who believe that they can own programs, generally put forward two lines of ar
	gument for this. The first one is “I wrote it, it is a child of my spirit, my he
	art, my soul is in this. How can anyone take it away from me? Wherever it goes i
	t's mine, mine, MINE!!”. Well, it's sort of strange that most of them signs agre
	ements saying it belongs to the company they work for.So I believe this is one o
	f the things you can easily talk yourself into believing is important, but you c
	an just as easily convince yourself it doesn't matter at all.Usually, these peop
	le use this argument to demand the right to control even how people can change a
	 program. They say: “Nobody should be able to mess up my work of art”. Well, ima
	gine that the person who invented a dish that you plan to cook had the right to 
	control how you can cook it, because it's his work of art. You want to leave out
	 the salt, but he says “Oh, no. I designed this dish, and it has to have this mu
	ch salt!” “But my doctor says it's not safe for me to eat salt. What can I do?”.
	Clearly, the person who is using the program is much closer to the event. The us
	e of the program affects him very directly, whereas it only has a sort of abstra
	ct relation to the person who wrote the program. And therefore, for the sake of 
	giving people as much control as possible over their own lives, it has to be the
	 user who decides those things.The second line of argument they make is the econ
	omic one. “How will people get payed to program?” they say, and there's a little
	 bit of real issue in this. But a lot of what they say is confusion. And the con
	fusion is, it's not at all the same to say “if we want to have a lot of people p
	rogramming we must arrange for them not to need to make a living in any other fa
	shion” on the one hand, and to say “We need to have the current system, you need
	 to get rich by programming” on the other hand. There's a big difference between
	 just making a living wage and making the kind of money programmers, at least in
	 the US make nowadays. They always say: “How will I eat?”, but the problem is no
	t really how “Will he eat?”, but “How will he eat sushi?”. “How will I have a ro
	of over my head?”, but the real problem is “How can he afford a condo?”.The curr
	ent system were chosen by the people who invest in software development, because
	 it gives them the possibility of making the most possible money, not because it
	's the only way anyone can ever come up with money to support a system developme
	nt effort. In fact, even as recently as ten and fifteen years ago it was common 
	to support software development in other ways. For example, those Digital operat
	ing systems that were free, even in the early seventies, were developed by peopl
	e who were paid for their work. Many useful programs has been developed at unive
	rsities. Nowadays those programs are often sold, but fifteen years ago they were
	 usually free, yet the people were paid for their work.When you have something l
	ike a program, like an infinite sandwich, like a road, which has to be built onc
	e, but once it is built it pretty much doesn't matter how much you use it, there
	's no cost in using it, generally it's better if we don't put any price on using
	 it. And there are plenty of those things that we develop now, and pay people to
	 build. For example, all the streets out there. It's very easy to find people wh
	o will program without being paid; it really is impossible to find people who wi
	ll build streets without being paid. Building streets is not creative and fun li
	ke programming. But we have plenty of streets out there, we do come up with the 
	money to pay them, and it's much better the way we do it than if if we said: “Le
	t's have companies go and build streets and put toll booths up, and then every t
	ime you turn another street corner, you pay another toll. And then the companies
	 that picked the good places to put their streets, they will be profitable, and 
	the others will go bankrupt.”There's a funny thing that happens whenever someone
	 comes up with a way of making lots of money by hoarding something. Until that t
	ime you've probably had lots and lots of people who were really enthusiastic and
	 eager to work in that field, the only sort of question is how can they get any 
	sort of livelihood at all. If we think of mathematicians for example, there are 
	a lot more people who want to be pure mathematicians than there is funding for a
	nybody to be pure mathematicians. And even when you do get funding, you don't ge
	t very much, they don't live well. And for musicians it's even worse. I saw a st
	atistics for how much the average musician, the average person devoting most of 
	his time trying to be a musician, in Massachusetts made; it was something like h
	alf the median income or less. It is barely enough to live on, it's difficult. B
	ut there are lots of them trying to do that. And then, somehow when it gets gene
	rally possible to get very well paid to do something, all those people disappear
	, and people start saying “nobody will do it unless they get paid that well”.And
	 I saw this happen in the field of programming. The very same people who used to
	 work at the AI lab and get payed very little and love it, now wouldn't dream of
	 working for less than fifty thousand dollars a year. What happened? When you da
	ngle before people the possibility of making lots of money, when they see that o
	ther people doing similar work are getting paid that much money, they feel that 
	they should get the same, and thus no-one is willing to continue the old way. An
	d it's easy after this has happened to think that paying people a lot of money i
	s the only way it could be, but that's not so. If the possibility of making a lo
	ts of money did not exist, you would have people who would accept doing it for a
	 little money, specially when it's something that is creative and fun.Now I saw 
	the unique world of the AI lab destroyed, and I saw that selling software was an
	 intrinsic part of what had destroyed it, and I saw also, as I explained before,
	 how you need to have free software in order to have a community like that. But 
	then thinking about it more, I realized all these ways in which hoarding softwar
	e hurts all of society, most specially by pressuring people to sell out their ne
	ighbors and causing social decay. The same spirit that leads people to watch whi
	le somebody in the street is getting stabbed and not tell anyone. The spirit tha
	t we can see so many companies all around us displaying all the time. And it was
	 clear to me I had a choice, I could become part of that world and feel unhappy 
	about what I was doing with my life, or I could decide to fight it. So I decided
	 to fight it. I've dedicated my career to try to rebuild the software sharing co
	mmunity, to trying to put an end to the phenomenon of hoarding generally useful 
	information. And the GNU system is a means to this end. It is a technical means 
	to a social end. With the GNU system, I hope to vaccinate the users against the 
	threat of the software hoarders.Right now the hoarders essentially claims the po
	wer to render a person's computer useless. There used to be people in the US, mo
	st commonly about fifty years ago, they were in the Mafia, they would go up to s
	tores and bars, especially bars when bars were illegal of course. They would go 
	up and say: “A lot of places around here have been burning down lately. You woul
	dn't want your place to burn down, would you? Well we can protect you from fires
	, you just have to pay us a thousand dollars a month, and we'll make sure you do
	n't have a fire here”. And this was called “the protection racket”. Now we have 
	something where a person says “You got a nice computer there, and you've got som
	e programs there that you're using. Well, if you don't want those programs to di
	sappear, if you don't want the police to come after you, you better pay me a tho
	usand dollars, and I'll give you a copy of this program with a license”, and thi
	s is called “the software protection racket”.Really all they're doing is interfe
	ring with everybody else doing what needs to be done, but they're pretending as 
	much to them selves as to the rest of us, that they are providing a useful funct
	ion. Well, what I hope is that when that software Mafia guy comes up and says, “
	You want those programs to disappear on your computer?”, the user can say “I'm n
	ot afraid of you any more. I have this free GNU software, and there's nothing yo
	u can do to me now.”Now, one of the justifications people sometimes offer for ow
	ning software, is the idea of giving people an incentive to produce things. I su
	pport the idea of private enterprise in general, and the idea of hope to make mo
	ney by producing things that other people like to use, but it's going haywire in
	 the field of software now. Producing a proprietary program is not the same cont
	ribution to society as producing the same program and letting it be free. Becaus
	e writing the program is just a potential contribution to society. The real cont
	ribution to the wealth of society happens only when the program is used. And if 
	you prevent the program from being used, the contribution doesn't actually happe
	n. So, the contribution that society needs is not these proprietary programs tha
	t everyone has such an incentive to make, the contribution we really want is fre
	e software, so our society is going haywire because it gives people an incentive
	 to do what is not very useful, and no incentive to do what is useful. Thus the 
	basic idea of private enterprise is not being followed, and you could even say t
	hat the society is neurotic. After all when an individual encourages in others b
	ehavior that is not good for that individual we call this a neurosis. Here socie
	ty is behaving in that fashion, encouraging programmers to do things that is not
	 good for society.I'm unusual. I'd rather believe that I'm a good member of soci
	ety and that I'm contributing something, than feel that I'm ripping society off 
	successfully, and that's why I've decided to do what I have done. But every one 
	is at least a little bit bothered by the feeling that they are getting paid to d
	o what's not really useful. So let's stop defending this idea of incentives to d
	o the wrong thing and let's at least try to come up with arrangements to encoura
	ge people to do the right thing, which is to make free software.

	-->
*/

////////////////////////////////////////////////////////////////////////////////

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <cstdlib> 
#include <ctime>

using namespace std;

////////////////////////////////////////////////////////////////////////////////

// Use a static data size for simplicity
//
#define DATA_SIZE (1024)

////////////////////////////////////////////////////////////////////////////////

template<typename _ty> vector<_ty>& get_dup(vector<_ty> left, vector<_ty> right)
{
	vector<_ty> ret;
	copy_if(left.begin(), left.end(), ret.begin(), 
		[&](_ty s)->bool {
			for (auto tmp : right)
				if (tmp == s)
					return true;
			return false;
		});
	return ret;
}

bool if_in(vector<unsigned long>& x, unsigned long that)
{
	for (auto x_temp : x)
		if (x_temp == that)
			return true;
	x.push_back(that);
	return false;
}

int delete_in(vector<int>& user, int dest)
{
	user.erase(remove_if(user.begin(), user.end(),
		[&] (int s) -> bool {
			if (s == dest % 10)
				return true;
			else if (s == (dest / 10) % 10)
				return true;
			else
				return false;
		}));
	return dest % 10;
}

void put_in(vector<int>& user, int dest)
{
	user.push_back(dest % 10);
	user.push_back((dest / 10) % 10);
}

unsigned long make_int(int size)
{
	random_device rd;
	unsigned long mi = rd() + rd();
	vector<unsigned short> arroverlap, arrtemp;
	if (mi < ::pow(10, size))
		return 0;
	for (; mi; mi /= 10)
		arroverlap.push_back(mi % 10);
	arroverlap.erase(remove_if(arroverlap.begin(), arroverlap.end(), 
		[&](unsigned short x)->bool{
		for (auto temp : arrtemp)
			if (temp == x)
				return true;
		arrtemp.push_back(x);
		return false;}));
	if(arrtemp.size() >= size)
	{
		unsigned long ret = 0;
		if (arroverlap[0] == 0)
			return 0;
		for (auto tmp : arroverlap)
			if (!size--) 
				return ret;
			else ret *= 10, ret += tmp;
	}
	return 0;
}

unsigned long make_int(vector<int> t, int size)
{
	//new_random_device rd(t.size());
	//random_shuffle(t.begin(), t.end(), rd);
	//auto engine = std::default_random_engine{};
	::random_shuffle(t.begin(), t.end(), [](int i)->int{ return ::rand() % i; });
	//::shuffle(t.begin(), t.end(), engine);
	unsigned long ret = 0;
	if (t[0] != 0)
		for (auto tmp : t)
			if (!size--) return ret;
			else ret *= 10, ret += tmp;
	return 0;
}

vector<int> put_in(int x)
{
	vector<int> v_int;
	for (; x; x /= 10)
		v_int.push_back(x % 10);
	return v_int;
}

////////////////////////////////////////////////////////////////////////////////

template<class _Number> class dove {
	int c1;
public:

	dove() : dove_get(1) {
		doveinit();
	}

	void start() {
		vector<int> pvi = put_in(c1);
		for(int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				cout << i  << " * " << j  << " = " << i * j << endl;
			}
		}
	}

private:

	void doveinit() {
		//size_t specific_rand = make_int(10);
		vector<int> in1;
		in1={ 0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		for (; !(c1 = make_int(in1, 10));)
			;
		//delete_in(in1, 2);
	}

	
	size_t dove_get;
};

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
	::srand ( unsigned ( ::time(0) ) );
	dove<int> kk;
	kk.start();
    return 0;
}