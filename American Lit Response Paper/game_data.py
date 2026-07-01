class GameData:
    """Contains all story content, scenes, and game logic"""


    def __init__(self):
        self.scenes = {
            "start": {
                "title": "Heading to the New World?",
                "image": "EnglandImage.webp",
                "text": """It is a pleasant day in England. You have heard of the discovery of the New World, as it is the talk of the town.
                You have heard about some explorers and their reports of the New World. While you are thinking of this, a newsboy walks up advertising the newspaper with the explorers' reports.
                You buy the paper and begin to read. There are three reports from Harriot, Raleigh, and Smith. Railigh's report "For the rest, which myself have seen, I will promise these things that follow, which I know to be true. Those who are desirous to discover and to see many nations may be satisfied within this river, which bringeth forth so many arms and branches leading to several countries and provinces, above 2,000 miles east and west and 800 miles south and north, and of these the most either rich in gold or in other merchandises. The common soldier shall here fight for gold, and pay himself, instead of pence, with plates of half-a-foot broad, whereas he breaketh his bones in other wars for provant and penury. Those commanders and chieftains that shoot at honour and abundance shall find there more rich and beautiful cities, more temples adorned with golden images, more sepulchres filled with treasure, than either Cortes found in Mexico or Pizarro in Peru. And the shining glory of this conquest will eclipse all those so far-extended beams of the Spanish nation. There is no country which yieldeth more pleasure to the inhabitants, either for those common delights of hunting, hawking, fishing, fowling, and the rest, than Guiana doth; it hath so many plains, clear rivers, and abundance of pheasants, partridges, quails, rails, cranes, herons, and all other fowl; deer of all sorts, porks, hares, lions, tigers, leopards, and divers other sorts of beasts, either for chase or food. It hath a kind of beast called cama or anta (tapir), as big as an English beef, and in great plenty. To speak of the several sorts of every kind I fear would be troublesome to the reader, and therefore I will omit them, and conclude that both for health, good air, pleasure, and riches, I am resolved it cannot be equalled by any region either in the east or west. Moreover the country is so healthful, as of an hundred persons and more, which lay without shift most sluttishly, and were every day almost melted with heat in rowing and marching, and suddenly wet again with great showers, and did eat of all sorts of corrupt fruits, and made meals of fresh fish without seasoning, of tortugas, of lagartos or crocodiles, and of all sorts good and bad, without either order or measure, and besides lodged in the open air every night, we lost not any one, nor had one ill-disposed to my knowledge; nor found any calentura or other of those pestilent diseases which dwell in all hot regions, and so near the equinoctial line."
                Smith's Report: "Heer nature and liberty affords vs that freely, which in England we want, or it costeth vs dearely. What pleasure can be more, then (being tired with any occa- sion a-shore) in planting Vines, Fruits, or Hearbs, in contriuing their owne Grounds, to the pleasure of their owne mindes, their Fields, Gardens, Orchards, Build- ings, Ships, and other works, &c. to recreate themselues before their owne doores, in their owne boates vpon the Sea, where man woman and childe, with a small hooke and line, by angling, may take diuerse sorts of excellent fish, at their pleasures ? And is it not pretty sport, to pull vp two pence, six pence, and twelue pence, as fast as you can hale and veare a line ? He is a very bad fisher, can- not kill in one day with his hooke and line, one, two, or three hundred Cods: which dressed and dryed, if they be sould there for ten shillings the hundred, though in England they will giue more then twentie; may not both the seruant, the master, and marchant, be well content with this gaine?"
                Harriot's Report on the Natives: "In respect of vs they are a people poore, and for
want of skill and iudgement in the knowledge and vse
of our things, doe esteeme our trifles before thinges of
greater value: Notwithstanding in their proper manner
considering the want of such meanes as we haue, they
seeme very ingenious; For although they haue no such
tooles, nor any such craftes, sciences and artes as wee;
yet in those thinges they doe, they shewe excellencie
of wit. And by howe much they vpon due consideration
shall finde our manner of knowledges and craftes to exceede theirs in perfection, and speed for doing or execution, by so much the more is it probable that they
shoulde desire our friendships & loue, and haue the
greater respect for pleasing and obeying vs. Whereby
may bee hoped if meanes of good gouernment bee vsed,
that they may in short time be brought to ciuilitie, and
the imbracing of true religion."
                Who do you choose to believe if any?""",
                "choices": [
                    ("I agree with Harriot's report (Enlightenment Path).", "franklin_scene"),
                    ("I agree with Raleigh's report (Writing and Religious Path).", "winthrop_sermon"),
                    ("I agree with Smith's report (Worldly Path).", "morton_scene"),
                    ("My life in England is better than a stupid new world anyway.", "Europe_Scene")
                ]
            },


            # --- Enlightenment Path Scenes ---
            "franklin_scene": {
                "title": "An Inventive Mind",
                "image": "FranklinHouse.webp",
                "text": """For the past few weeks, all anyone has been talking about is a new book called Poor Richard's Almanac. It is a very big hit, and many are discussing the advice. One day, while you are browsing a copy in a government office, Benjamin Franklin stops and sees that you are reading Poor Richard's Almanac. "Not bad, right?" he says. "That advice seems to be really popular with today's society. I remember one particular saying that everyone has been talking about."
"Early to bed, Early to rise makes a man healthy, wealthy, and wise," you recite.
Franklin seems impressed by this and a bit happy as he says, "We should always be striving for productivity and to be virtuous. After all, I hope to attain moral perfection, which is why I have my list of 13 virtues. It was originally 12, but a friend said I should add in humility, which was a good idea. That does remind me, I can check that box later tonight."
"What else do you do in your free time when you are not practicing your virtues?" you ask.
"Honestly, I do a bit of everything: I studied electricity and how to harness it, writing, inventing, printing in a former life, scientist, philosopher, and statesman, just for a short list, my good fellow," he said cheerfully. You ask Franklin about more of his interests, about being industrious, and his views on Justice. He says something similar to John Adams that people must be free and have the right to pursue their own lives, as a summary of your long conversation. As you walk out of the building, you think:""",
                "choices": [
                   ("Franklin is right, we should be more industrious.", "adams_scene"),
                   ("I think I will continue with my life just the way it is, no need to listen to his advice.", "adams_scene"),
                   ("Who would even believe this stuff? Are people that gullible?", "adams_scene"),
                   ("This place is too crazy for me. Back to England.", "Europe_Scene")
                ]
            },


            "adams_scene": {
                "title": "A Haunting Reminder For America",
                "image": "AddamsHouse.jpg",
                "text": """You have finally arrived in Boston, and you see an old friend, Abigail Adams. John Adams is currently in Boston for a short time, and you actually needed to meet with him. Abigail invites you over for lunch, and you agree and head to the Adams family's house. When you get there, Abigail seems happy that John is finally back from all his work. When you ask her about this, she shows you all the letters they have written to each other while John was away. Abigail says, "I really have had to do a lot at the house with taking care of the kids and making gunpowder to help in the war efforts." Abigail looks at John, a little displeased, and John replies, "What, I have had to do a lot too. It is not like this country will free itself from the Crown and just self-govern. We have had a lot to do just in setting up the country and fighting the crown to gain our independence. If we want the freedom and liberty that we seek, then we have to fight for it, and then we can be free to learn, govern, and worship as we please."
                "I am sure that is all very hard work," Abigail replies a bit condescendingly, "Just be sure you include women when you set up the government. I already feel out of depth with teaching the children." You talk some more, and on your way back, Abigail's words haunting the back of your mind, you think:""",
                "choices": [
                    ("I think Abigail has the right idea, we should help women thrive.", "jefferson_scene"),
                    ("John is right, we need to focus on the country first.", "jefferson_scene"),
                    ("What we really need is a balance of both in order for our country to thrive.", "jefferson_scene"),
                    ("This place is too crazy for me. Back to England.", "Europe_Scene")
                ]
            },
           
            "jefferson_scene": {
                "title": "Freedom Of Intellect, Government, and Religion",
                "image": "JeffersonHouse.jpg",
                "text": """For the past few weeks, all anyone has been talking about is the creation and signature of the Declaration of Independence. Some loyalists to the crown think this is a terrible idea despite the clear taxation without representation that has been going on. The event now called the Boston Tea Party also made waves as many talked about this act of defiance towards England. Those who want to break away talk about France aiding the colonies, as they have a plight against England as well. Thomas Jefferson claims that he did a lot of the work on the Declaration of Independence, and this is unsurprising, having met Franklin and John Adams. The declaration discusses a lot about liberty and the ability to live a free life, especially in religion, education, and politics. The local paper has a small section of the declaration for all to read: "We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.--That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, --That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness." As you reflect on the current state of events, you think:""",
                "choices": [
                    ("Viva la revolution, let's gain our freedom and independence, no more king.", "paine_scene"),
                    ("I don't think we should break from Endland so soon, what if we fail in our independence?", "paine_scene"),
                    ("The king will surely hear of this and establish his blessed rule back over us as it is meant to be.", "paine_scene"),
                    ("I have to get out of this revolution before I am pushed to fight.", "Europe_Scene")
                ]
            },


            "paine_scene": {
                "title": "A Common Pain",
                "image": "ColonialBuilding.webp",
                "text": """The dawn of the Revolutionary War is upon the colonies, and you are a bit conflicted about joining the war effort. As you are thinking about this, a newsboy shows up with the daily paper. You see a paper written by Thomas Paine called Common Sense. From what you have heard of him, he wrote about treating women better, something Abigail Adams would agree with. You also know he has discussed his thoughts on Christianity and Deism, and he claims Deism is superior since you do not need to believe in anything supernatural. You read a small excerpt: "As a long and violent abuse of power, is generally the Means of calling the right of it in question (and in Matters too which might never have been thought of, had not the Sufferers been aggravated into the inquiry) and as the King of England hath undertaken in his own Right, to support the Parliament in what he calls Theirs, and as the good people of this country are grievously oppressed by the combination, they have an undoubted privilege to inquire into the pretensions of both, and equally to reject the usurpation of either." After reading this, you feel that joining by Paine's argument is:""",
                "choices": [
                    ("NO MORE KINGS! I am absolutely joining the war.", "End_Route_Scene"),
                   ("I would rather let this play out and see who wins. I will stay neutral.", "End_Route_Scene"),
                   ("This is only going to bring nothing but conflict, but some people like trouble.", "End_Route_Scene"),
                   ("This is not even a real fight. The colonists don't have a chance. I am going back home", "Europe_Scene")
                ]
            },


            # --- Writing Path Scenes ---
            "winthrop_sermon": {
                "title": "A City Upon A Hill",
                "image": "ColonialChurch.jpg",
                "text": """On the boat over, you hear John Winthrop talking about his notes for his upcoming sermon to remind everyone of why they are coming to the new world. The next day as you near the main land you hear him saying "wee must uphold a familiar Commerce together in all meekenes, gentlenes, patience and liberallity, wee must delight in eache other, make others Condicions our owne rejoyce together, mourne together, labour, and suffer together, allwayes haveing before our eyes our Commission and Community in the worke, our Community as members of the same body, soe shall wee keepe the unitie of the spirit in the bond of peace, the Lord will be our God and delight to dwell among us, as his owne people and will commaund a blessing upon us in all our wayes, soe that wee shall see much more of his wisdome power goodnes and truthe then formerly wee have beene acquainted with, wee shall finde that the God of Israell is among us, when tenn of us shall be able to resist a thousand of our enemies, when hee shall make us a prayse and glory, that men shall say of succeeding plantacions: the lord make it like that of New England: for wee must Consider that wee shall be as a Citty upon a Hill, the eies of all people are uppon us; soe that if wee shall deale falsely with our god in this worke wee have undertaken and soe cause him to withdrawe his present help from us, wee shall be made a story and a byword through the world..." Once the sermon is over you think about what was said and how you respond to it.""",
                "choices": [
                    ("We should become the new Israel and succeed where they failed!", "bradford_encounter"),
                   ("This is a bit over ambitious, but I see the point and we should strive for it.", "bradford_encounter"),
                   ("This is way too much religion for me, I just want to start a new life here.", "bradford_encounter"),
                   ("I need the next boat back to England. This is too much religious fervor.", "Europe_Scene")
                ]
            },


            "bradford_encounter": {
                "title": "Religious Detication",
                "image": "ColonialBuilding.webp",
                "text": """One day, while you are going about your business, you come across Bradford, the leader of the Plymouth colony. You have heard some unflattering rumors about him, such as how stuck up he is and that his opinion is the only right one. You decide to talk with him anyway and ask him his thoughts on the New World. He says, "We are guided here by the providence of God as a place to rest from the persecution we faced in Holland and England. God has given us this land, and it is our destiny to seize it and use it to fully glorify God. Those strangers who would do otherwise or cause a ruckus like Morton should not be here. This colony must remain pure if we are to have peace and progress through God's protection." After talking for a bit longer, you walk away thinking about your experience, and you think:""",
                "choices": [
                    ("His piety and devotion are unmatched. I should try to emulate him.", "bradstreet_poetry"),
                    ("This does not sound like what I read from the Bible; it may be going a bit too far.", "bradstreet_poetry"),
                    ("We need more religious tolerance here, after al,l the Bible is all about loving your neighbour.", "bradstreet_poetry"),
                    ("No thanks, I am going back home where religion is a bit more normal.", "Europe_Scene")
                ]
            },


            "bradstreet_poetry": {
                "title": "Contemplating Nature And The Divine Creator",
                "image": "ColonialBuilding.webp",
                "text": """A few years later, you hear the tale of a female poet named Anne Bradstreet. Apparently, her brother-in-law published her poems without her consent. You can easily get a copy, as many don't even think she wrote it. You read a section from Contemplations: "Thy swift Annual and diurnal Course, Thy daily straight and yearly oblique path, Thy pleasing fervour, and thy scorching force, All mortals here the feeling knowledge hath. Thy presence makes it day, thy absence night, Quaternal seasons caused by thy might: Hail Creature, full of sweetness, beauty, and delight. Art thou so full of glory that no Eye Hath strength thy shining Rays once to behold? And is thy splendid Throne erect so high? As, to approach it, can no earthly mould. How full of glory then must thy Creator be? Who gave this bright light luster unto thee: Admir'd, ador'd for ever be that Majesty. Silent alone where none or saw, or heard, In pathless paths I lead my wand'ring feet. My humble Eyes to lofty Skies I rear'd To sing some Song my mazed Muse thought meet.
My great Creator I would magnifie, That nature had thus decked liberally: But Ah and Ah again, my imbecility!" You think this is:""",
                "choices": [
                    ("The world does truly reflect God's masterful handiwork absolutely spot on!", "edward_taylor_scene"),
                    ("Surprisingly, a woman wrote this considering the times.", "edward_taylor_scene"),
                    ("Poetry has never been my thing, and adding religion does not help.", "edward_taylor_scene"),
                    ("These colonies have too many weird values. I am going back home where things are as they should be.", "Europe_Scene")
                ]
            },
           
            "edward_taylor_scene": {
                "title": "Reflections Of God's Fun",
                "image": "ColonialChurch.jpg",
                "text": """One Sunday after church, a visiting preacher walks up to you. He introduces himself as Edward Taylor. You tell him that you were impressed with his thoughts before communion was served. You ask about his process for keeping himself focused. He replies, "I write poetry to focus my mind before I partake of communion, because if my mind is focused, then I can help everyone have their minds centered. I can read a part of what I have written." He begins to read "Infinity, when all things it beheld
In Nothing, and of Nothing all did build,
Upon what base was fixed the lath wherein
He turned this globe and rigalled it so trim?
Who blew the bellows of His furnace vast?
Or held the mold wherein the world was cast?
Who laid its cornerstone? Or whose command?
Where stand the pillars upon which it stands?
Who laced and filleted the earth so fine,
With rivers like green ribbons smaragdine?
Who made the seas its selvedge and it locks
Like a quilt ball within a silver box?
Who spread its canopy? Or curtains spun?
Who in this bowling alley bowled the sun?
Who made it always when it rises set,
To go at once both down, and up to get?
Who the curtain rods made for this tapestry?
Who hung the twinkling lanterns in the sky?
Who? Who did this? Or who is He? Why, know
It's only Might Almighty this did do." After he finishes, he says, "I do like to have a little fun in my meditations as the bowling part describes, but please do not tell the other Puritans, as they may get a little upset." As you walk out of church, you think:""",
                "choices": [
                    ("His levity reflects what I think God desires in each of us to have fun and worship him.", "edwards_sermon"),
                    ("Why should we be having fun? Is it not fun that takes us away from God?", "edwards_sermon"),
                    ("These meditations are interesting, I might try some of them before church as well.", "edwards_sermon"),
                    ("No fun for me, I am going back home to England.", "Europe_Scene")
                ]
            },


            "edwards_sermon": {
                "title": "Backsliding From Religious Affairs",
                "image": "ColonialChurch.jpg",
                "text": """After church on a Sunday morning, as usual, everyone is talking about the service and what they are going to do for the rest of the day. This time, however, they are specifically mentioning the preacher, Jonathan Edwards, whom they really disliked. It is said that he has been going from church to church and may have to minister to the natives if things get really bad and no one wants to hear him preach. One says, "I heard he was kicked out of his home congregation for mentioning their sins and calling people out." Another replies with "I heard that too from a few towns over, and he even thinks only the saved should partake of communion rather than all who go." They all laugh at that ridiculous idea, as the old traditions held no power in the churches in America. You silently think, supposedly that is true, then you hear them talk about the sermon, and that it was far too scary for their liking. You recall with startling accuracy what Edwards said, "The unseen, unthought-of ways and means of persons going suddenly out of the world are innumerable and inconceivable. Unconverted men walk over the pit of hell on a rotten covering, and there are innumerable places in this covering so weak that they will not bear their weight, and these places are not seen. The arrows of death fly unseen at noon-day; the sharpest sight cannot discern them. God has so many different unsearchable ways of taking wicked men out of the world and sending them to hell, that there is nothing to make it appear, that God had need to be at the expense of a miracle, or go out of the ordinary course of his providence, to destroy any wicked man, at any moment. All the means that there are of sinners going out of the world, are so in God's hands, and so universally and absolutely subject to his power and determination, that it does not depend at all the less on the mere will of God, whether sinners shall at any moment go to hell, than if means were never made use of, or at all concerned in the case." The two then turn to you and ask "what are your thoughts on all this?" """,
                "choices": [
                    ("He is right, though. God does have all the power. Spiders dangling over lava, remember?", "End_Route_Scene"),
                    ("This is definitely too extreme, and no wonder he is getting banned from all churches.", "End_Route_Scene"),
                    ("Religion is a source of comfort, not fear.", "End_Route_Scene"),
                    ("I am going back home where all the sermons are comfortable and people understand the Bible.", "Europe_Scene")
                ]
            },


            # --- Worldly Scenes ---
            "morton_scene": {
                "title": "Trouble In Puritan Paradise",
                "image": "Morton.jpg",
                "text": """One day, as you are walking into town, you hear some of the townspeople gossiping about a guy called Morton up in Virginia. "They say he is very good at upsetting the Puritans," one says. Another comment, "I heard he was courting the native women and even some women who wanted to join in and have some fun." A third townsperson jumps in saying, "I heard he set up a maypole and even made his own poem praising the Greek gods just to really enrage the Puritans." A few days later, a newsboy hands you the paper, and you see that Morton has been kicked out for the second time. A villager asks you, "Do you think he will come back?" """,
                "choices": [
                    ("I agree with the Puritans, he deserves to be removed.", "native_speeches_scene"),
                    ("The Puritans are just a bit grumpy and everything Morton is doing is harmless.", "native_speeches_scene"),
                    ("A bit of moderation is what is needed, why can't we have fun and be serious? There is a time for everything.", "native_speeches_scene"),
                    ("Might as well go join him in England since we can't have any fun.", "Europe_Scene")
                ]
            },


            "native_speeches_scene": {
                "title": "The 'Other' People",
                "image": "ColonialBuilding.webp",
                "text": """Throughout your stay in the new world, you hear of how the natives are being treated and what the other settlers are doing to them. You have heard about land disputes and how the settlers are intentionally charging more for their wares. The natives have been outraged about this for a while, and many have spoken out against the violence against them. You ponder this situation and arrive at this conclusion:""",
                "choices": [
                    ("This is unjust, we are just like the King of England.", "rowlandson_narrative"),
                    ("Why can't we just coexist and stop this infighting?", "rowlandson_narrative"),
                    ("We are taking this land fairly too; it should be ours.", "rowlandson_narrative"),
                    ("I would rather live in peace than have the chance to be killed or captured, back to England.", "Europe_Scene")
                ]
            },


            "rowlandson_narrative": {
                "title": "A Remove From Home",
                "image": "RowlandsonImage.jpg",
                "text": """After King Philip's War, as part of the help effort, you are sent to a frontier village in Massachusetts. The village is currently being repaired, and a pile of charred wood lies a few steps outside the village. You see a lady carrying a Bible and go talk to her about the relief effort. She introduces herself as Mary Rowlandson, and she tells you a bit about her story. "They came to our village suddenly and started burning our homes and forcing us to be captured or die. It was quite scary, and I remember thinking I would rather die than be captured, but in that moment, I changed my mind. They took me along with my daughter and son, whom I would not see for a while, on the journey. I had only a small child with me, but the child would die only a few days into the journey. It was hard, and I went through twenty removes of walking and riding before I was set free. I did not know if I would make it, but God saw me through...they gave us a pick of some goods they had taken from the houses, including a Bible. I asked for that, and it gave me all the comfort I needed... I knew that God was helping me through these trials, and this was testing my faith to make me stronger." You get to work helping, and at the end, everyone in the village is grateful for the help in repairing the village. As you travel back home, you think:""",
                "choices": [
                    ("Her perseverance is quite something, I wish I had that kind of faith.", "End_Route_Scene"),
                    ("This seems a little too convenient, especially how God was always there. I can't fully trust this.", "End_Route_Scene"),
                    ("We have to trust God even when it is hard to see the path forward.", "End_Route_Scene"),
                    ("I don't want any more conflict. I am out of here.", "Europe_Scene")
                ]
            },


            # --- Ending Scenes ---
            "Europe_Scene":{
                "title": "Home",
                "image": "EnglandImage.webp",
                "text": """You return to England and live the rest of your life quietly. The New World is not fascinating to you anymore.""",
                "choices": [
                    ("Play Again", "RESTART"),
                    ("End Game", "QUIT_GAME")
                ]
            },


            "End_Route_Scene":{
                "title": "A New Home",
                "image": "ColonialBuilding.webp",
                "text": """Your life in the colonies is quite pleasant, free from the rule of the King and England. You have watched a new experiment happen and anticipate the results of the great experiment.""",
                "choices": [
                    ("Play Again", "RESTART"),
                    ("End Game", "QUIT_GAME")
                ]
            }
        }


    def get_scene(self, scene_id):
        """Get a specific scene by ID"""
        return self.scenes.get(scene_id, None)


    def add_scene(self, scene_id, scene_data):
        """Add a new scene (useful for expanding the game)"""
        self.scenes[scene_id] = scene_data


    def get_all_scenes(self):
        """Get all available scenes"""
        return self.scenes.keys()
