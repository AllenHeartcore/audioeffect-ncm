# ncm-audioeffect
Reverse engineered audio effect module for NetEase Cloud Music

<table>
    <thead>
        <tr>
            <th rowspan=2></th>
            <th rowspan=2></th>
            <th rowspan=2></th>
            <th colspan=2>BT</th>
            <th rowspan=2>EQ</th>
            <th colspan=6>RVB</th>
            <th colspan=4>SE</th>
        </tr>
        <tr>
            <th>Bass</th>
            <th>Treble</th>
            <th>ER</th>
            <th>OL</th>
            <th>RVB</th>
            <th>TC</th>
            <th>Presence</th>
            <th>Stereoizer</th>
            <th>SShaper</th>
            <th>Ambience</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=7>Genre</td>
            <td>Electronic</td> <td>迷幻电音</td>
            <td>3</td> <td>2</td>
            <td>[5, 6.09, 2.2, 0, -1.6, 1.5, 0, 1, 2.57, 3.77]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Electronic+</td> <td>动感电音</td>
            <td></td> <td></td>
            <td>[4, 4, 3, 1, -1, -2, -1, 2, 4, 4]</td>
            <td>Pattern 4, RSize 80, SDelay 40</td>
            <td>Dry 0, ER -22, RVB -24</td>
            <td>PDelay 50, DTime 2.5, HFDamping 6.5, Density 50, RShape 20, Q 8, Diffusion 85, SWidth 180</td>
            <td>
                [1] Gain -2, Freq 200, Q .5<br>
                [2] Gain -1, Freq 2000, Q .5<br>
                [3] Gain 2, Freq 10000, Q .5
            </td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Rock</td> <td>摇滚经典</td>
            <td></td> <td></td>
            <td>[-5.7, 0, 1.5, -3.81, -.2, -1.1, .6, 1.5, 1.91, 1.91]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td>3</td> <td>2</td> <td>ON</td> <td>5</td>
        </tr>
        <tr>
            <td>HipHop</td> <td>嘻哈音效</td>
            <td>2</td> <td>2</td>
            <td>[5.6, 5.09, 2, .5, -2, 1.2, 3.79, .5, 1.5, 4]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>ACG</td> <td>纯净ACG</td>
            <td>2</td> <td>3</td>
            <td>[4, 6.19, 1.5, -.5, -.8, 2, 5.19, 1, -1.5, 4]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Folk</td> <td>民谣音效</td>
            <td></td> <td>1</td>
            <td>[0, 3, 0, -.8, 1.5, 4.8, 5.8, 3.2, -.5, 2]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Classical</td> <td>婉约古风</td>
            <td>2</td> <td>2</td>
            <td>[4, 2, 0, -.5, -1, 3.5, 4.5, 1, -1, 3]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td rowspan=2>EQ</td>
            <td>Bass</td> <td>极重低音</td>
            <td>3</td> <td></td>
            <td>[6, 4.5, 3.2, 2.09, 0, 0, 0, 0, 0, 0]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Vocal</td> <td>清澈人声</td>
            <td></td> <td></td>
            <td>[-1.5, -1, 0, 1.79, 4, 3.79, 1.79, .5, -1, 1]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td rowspan=4>Spatial</td>
            <td>Surr</td> <td>3D环绕</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
            <td>6</td> <td>4</td> <td>ON</td> <td>1</td>
        </tr>
        <tr>
            <td>Stereo</td> <td>独享立体声</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td>ON</td> <td></td>
        </tr>
        <tr>
            <td>StereoSurr</td>
            <td>环绕立体声</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td>ON</td> <td>1</td>
        </tr>
        <tr>
            <td>StereoCrystal</td>
            <td>水晶立体声</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td>ON</td> <td>6</td>
        </tr>
        <tr>
            <td rowspan=5>Scene</td>
            <td>Concert</td> <td>音乐厅</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td>ON</td> <td>3</td>
        </tr>
        <tr>
            <td>Church</td> <td>教堂混响</td>
            <td></td> <td></td>
            <td></td>
            <td>Pattern 0, RSize 80, SDelay 40</td>
            <td>Dry 0, ER -15, RVB -20</td>
            <td>PDelay 25, DTime 2.4, HFDamping 2, Density 60, RShape 80, Q 6, Diffusion 80, SWidth 180</td>
            <td>
                [1] Gain -2, Freq 160, Q 1<br>
                [2] Gain -2.5, Freq 2000, Q .5<br>
                [3] Gain -3, Freq 8000, Q .5
            </td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Live</td> <td>演唱会现场</td>
            <td>3</td> <td>2</td>
            <td>[5.59, 5, 3, 0, -1, 0, 3.09, 4.5, 4, 5]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>LiveSurr</td> <td>狂嗨LIVE</td>
            <td>12</td> <td>-12</td>
            <td>[-6, -6.5, -3.7, -9.93, -12, -12, -12, -12, -12, -12]</td>
            <td>Pattern 24, RSize 50, SDelay 40</td>
            <td>Dry 0, ER -3, RVB -20</td>
            <td>PDelay 0, DTime 3.59, HFDamping 2, Density 60, RShape 40, Q 8, Diffusion 40, SWidth 110</td>
            <td>
                [1] Gain -1, Freq 200, Q 1<br>
                [2] Gain -3, Freq 2000, Q .5<br>
                [3] Gain 0, Freq 8000, Q .5
            </td>
            <td>10</td> <td>10</td> <td>ON</td> <td></td>
        </tr>
        <tr>
            <td>Livehouse</td> <td>LiveHouse现场</td>
            <td></td> <td></td>
            <td></td>
            <td>Pattern 4, RSize 70, SDelay 40</td>
            <td>Dry 0, ER -23, RVB -20</td>
            <td>PDelay 25, DTime 1.5, HFDamping 2.79, Density 60, RShape 40, Q 8, Diffusion 80, SWidth 150</td>
            <td>
                [1] Gain -1, Freq 200, Q 1<br>
                [2] Gain -3, Freq 2000, Q .5<br>
                [3] Gain -5, Freq 8000, Q .5
            </td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td rowspan=3>Custom</td>
            <td>NINEONE#</td> <td>专属音效</td>
            <td></td> <td></td>
            <td>[0, 0, -1, -1, -2, 1, 2, 2, 0, 0]</td>
            <td>Pattern 4, RSize 60, SDelay 0</td>
            <td>Dry -1.5, ER -28, RVB -22</td>
            <td>PDelay 5, DTime 1.2, HFDamping 3.5, Density 35, RShape 40, Q 8, Diffusion 100, SWidth 180</td>
            <td>
                [1] Gain -24, Freq 250, Q .5<br>
                [2] Gain 2, Freq 2000, Q .5<br>
                [3] Gain 1, Freq 12000, Q .5
            </td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>Xiaowang</td> <td>毛不易《小王》专属音效</td>
            <td></td> <td></td>
            <td>[-5, -4, -2, -.5, 1.5, 2.5, 0, -3, -5, -5]</td>
            <td>Pattern 4, RSize 60, SDelay 0</td>
            <td>Dry 0, ER -14, RVB -80</td>
            <td>PDelay 25, DTime 1, HFDamping 2.25, Density 80, RShape 100, Q 2, Diffusion 100, SWidth 180</td>
            <td>
                [1] Gain -2, Freq 80, Q .5<br>
                [2] Gain 0, Freq 1000, Q 1<br>
                [3] Gain -2, Freq 8000, Q .5
            </td>
            <td></td> <td></td> <td></td> <td></td>
        </tr>
        <tr>
            <td>BWMRSZN</td> <td>《不完美人生指南》专属音效</td>
            <td></td> <td></td>
            <td>[-1, -1, -2, -3, -2, -2, -1, -1, -1, -1]</td>
            <td></td> <td></td> <td></td> <td></td>
            <td>2</td> <td>.5</td> <td></td> <td>1.5</td>
        </tr>
    </thead>
</table>
