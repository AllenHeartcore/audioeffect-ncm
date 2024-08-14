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
            <th>IL</th>
            <th>OL</th>
            <th>RL</th>
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
        </tr>
        <!-- | genre_electronic+ | 动感电音 | [4, 4, 3, 1, -1, -2, -1, 2, 4, 4] | | {'er': {'pattern': 4, 'rsize': 80, 'sdelay': 40}, 'rvb': {'pdelay': 50, 'dtime': 2.5, 'hfdamping': 6.5, 'density': 50, 'rshape': 20, 'q': 8, 'diffusion': 85, 'swidth': 180}, 'tc': {'f': [{'band': 1, 'insert': 3, 'curve': 0, 'gain': -2, 'freq': 200, 'q': 0.5}, {'band': 2, 'insert': 3, 'curve': 1, 'gain': -1, 'freq': 2000, 'q': 0.5}, {'band': 3, 'insert': 3, 'curve': 2, 'gain': 2, 'freq': 10000, 'q': 0.5}]}, 'il': {'center': 0, 'lfe': 0}, 'ol': {'dry': 0, 'er': -22, 'rvb': -24}, 'rl': {'front': 0, 'rear': 0, 'center': 0, 'lfe': 0}} | |
        | genre_rock | 摇滚经典 | [-5.7, 0, 1.5, -3.81, -0.2, -1.1, 0.6, 1.5, 1.91, 1.91] | | | {'ambience': 3, 'presence': 2, 'sshaper': True, 'stereoizer': 5} |
        | genre_hiphop | 嘻哈音效 | [5.6, 5.09, 2, 0.5, -2, 1.2, 3.79, 0.5, 1.5, 4] | {'bass': 2, 'treble': 2} | | |
        | genre_acg | 纯净ACG | [4, 6.19, 1.5, -0.5, -0.8, 2, 5.19, 1, -1.5, 4] | {'bass': 2, 'treble': 3} | | |
        | genre_folk | 民谣音效 | [0, 3, 0, -0.8, 1.5, 4.8, 5.8, 3.2, -0.5, 2] | {'bass': 0, 'treble': 1} | | |
        | genre_classical | 婉约古风 | [4, 2, 0, -0.5, -1, 3.5, 4.5, 1, -1, 3] | {'bass': 2, 'treble': 2} | | |
        | eq_bass | 极重低音 | [6, 4.5, 3.2, 2.09, 0, 0, 0, 0, 0, 0] | {'bass': 3, 'treble': 0} | | |
        | eq_vocal | 清澈人声 | [-1.5, -1, 0, 1.79, 4, 3.79, 1.79, 0.5, -1, 1] | | | |
        | spatial_surr | 3D环绕 | | | | {'presence': 6, 'stereoizer': 4, 'sshaper': True, 'ambience': 1} |
        | spatial_stereo | 独享立体声 | | | | {'presence': 0, 'stereoizer': 0, 'sshaper': True, 'ambience': 0} |
        | spatial_stereo_surr | 环绕立体声 | | | | {'presence': 0, 'stereoizer': 0, 'sshaper': True, 'ambience': 1} |
        | spatial_stereo_crystal | 水晶立体声 | | | | {'presence': 0, 'stereoizer': 0, 'sshaper': True, 'ambience': 6} |
        | scene_concert | 音乐厅 | | | | {'presence': 0, 'stereoizer': 0, 'sshaper': True, 'ambience': 3} |
        | scene_church | 教堂混响 | | | {'er': {'pattern': 0, 'rsize': 80, 'sdelay': 40}, 'rvb': {'pdelay': 25, 'dtime': 2.4, 'hfdamping': 2, 'density': 60, 'rshape': 80, 'q': 6, 'diffusion': 80, 'swidth': 180}, 'tc': {'f': [{'band': 1, 'insert': 3, 'curve': 0, 'gain': -2, 'freq': 160, 'q': 1}, {'band': 2, 'insert': 3, 'curve': 1, 'gain': -2.5, 'freq': 2000, 'q': 0.5}, {'band': 3, 'insert': 3, 'curve': 2, 'gain': -3, 'freq': 8000, 'q': 0.5}]}, 'il': {'center': 0, 'lfe': 0}, 'rl': {'front': 0, 'rear': 0, 'center': 0, 'lfe': 0}, 'ol': {'dry': 0, 'er': -15, 'rvb': -20}} | |
        | scene_live | 演唱会现场 | [5.59, 5, 3, 0, -1, 0, 3.09, 4.5, 4, 5] | {'bass': 3, 'treble': 2} | | |
        | scene_live_surr | 狂嗨LIVE | [-6, -6.5, -3.7, -9.93, -12, -12, -12, -12, -12, -12] | {'bass': 12, 'treble': -12} | {'er': {'pattern': 24, 'rsize': 50, 'sdelay': 40}, 'rvb': {'pdelay': 0, 'dtime': 3.59, 'hfdamping': 2, 'density': 60, 'rshape': 40, 'q': 8, 'diffusion': 40, 'swidth': 110}, 'tc': {'f': [{'band': 1, 'insert': 3, 'curve': 0, 'gain': -1, 'freq': 200, 'q': 1}, {'band': 2, 'insert': 3, 'curve': 1, 'gain': -3, 'freq': 2000, 'q': 0.5}, {'band': 3, 'insert': 3, 'curve': 2, 'gain': 0, 'freq': 8000, 'q': 0.5}]}, 'il': {'center': 0, 'lfe': 0}, 'rl': {'front': 0, 'rear': 0, 'center': 0, 'lfe': 0}, 'ol': {'dry': 0, 'er': -3, 'rvb': -20}} | {'presence': 10, 'stereoizer': 10, 'sshaper': True, 'ambience': 0} |
        | scene_livehouse | LiveHouse现场 | | | {'er': {'pattern': 4, 'rsize': 70, 'sdelay': 40}, 'rvb': {'pdelay': 25, 'dtime': 1.5, 'hfdamping': 2.79, 'density': 60, 'rshape': 40, 'q': 8, 'diffusion': 80, 'swidth': 150}, 'tc': {'f': [{'band': 1, 'insert': 3, 'curve': 0, 'gain': -1, 'freq': 200, 'q': 1}, {'band': 2, 'insert': 3, 'curve': 1, 'gain': -3, 'freq': 2000, 'q': 0.5}, {'band': 3, 'insert': 3, 'curve': 2, 'gain': -5, 'freq': 8000, 'q': 0.5}]}, 'il': {'center': 0, 'lfe': 0}, 'rl': {'front': 0, 'rear': 0, 'center': 0, 'lfe': 0}, 'ol': {'dry': 0, 'er': -23, 'rvb': -20}} | |
        | custom_nineone | NINEONE#专属音效 | [0, 0, -1, -1, -2, 1, 2, 2, 0, 0] | | {'er': {'pattern': 4, 'rsize': 60, 'sdelay': 0}, 'il': {'center': 0, 'lfe': 0}, 'ol': {'dry': -1.5, 'er': -28, 'rvb': -22}, 'rl': {'center': 0, 'front': 0, 'lfe': 0, 'rear': 0}, 'rvb': {'density': 35, 'diffusion': 100, 'dtime': 1.2, 'hfdamping': 3.5, 'pdelay': 5, 'q': 8, 'rshape': 40, 'swidth': 180}, 'tc': {'f': [{'band': 1, 'curve': 0, 'freq': 250, 'gain': -24, 'insert': 3, 'q': 0.5}, {'band': 2, 'curve': 1, 'freq': 2000, 'gain': 2, 'insert': 3, 'q': 0.5}, {'band': 3, 'curve': 2, 'freq': 12000, 'gain': 1, 'insert': 3, 'q': 0.5}]}} | |
        | custom_xiaowang | 毛不易《小王》专属音效 | [-5, -4, -2, -0.5, 1.5, 2.5, 0, -3, -5, -5] | | {'er': {'pattern': 4, 'rsize': 60, 'sdelay': 0}, 'il': {'center': 0, 'lfe': 0}, 'ol': {'dry': 0, 'er': -14, 'rvb': -80}, 'rl': {'center': 0, 'front': 0, 'lfe': 0, 'rear': 0}, 'rvb': {'density': 80, 'diffusion': 100, 'dtime': 1, 'hfdamping': 2.25, 'pdelay': 25, 'q': 2, 'rshape': 100, 'swidth': 180}, 'tc': {'f': [{'band': 1, 'curve': 0, 'freq': 80, 'gain': -2, 'insert': 3, 'q': 0.5}, {'band': 2, 'curve': 1, 'freq': 1000, 'gain': 0, 'insert': 3, 'q': 1}, {'band': 3, 'curve': 2, 'freq': 8000, 'gain': -2, 'insert': 3, 'q': 0.5}]}} | |
        | custom_bwmrszn | 《不完美人生指南》专属音效 | [-1, -1, -2, -3, -2, -2, -1, -1, -1, -1] | | | {'ambience': 2, 'presence': 0.5, 'sshaper': False, 'stereoizer': 1.5} | -->
        <tr>
            <td>Electronic+</td> <td>动感电音</td>
            <td></td> <td></td>
            <td>[4, 4, 3, 1, -1, -2, -1, 2, 4, 4]</td>
            <td>Pattern 4, RSize 80, SDelay 40</td>
            <td>PDelay 50, DTime 2.5, HFDamping 6.5, Density 50, RShape 20, Q 8, Diffusion 85, SWidth 180</td>
            <td>[1] Insert 3, Curve 0, Gain -2, Freq 200, Q 0.5<br>[2] Insert 3, Curve 1, Gain -1, Freq 2000, Q 0.5<br>[3] Insert 3, Curve 2, Gain 2, Freq 10000, Q 0.5</td>
            <td>Center 0, LFE 0</td>
            <td>Dry 0, ER -22, RVB -24</td>
            <td>Front 0, Rear 0, Center 0, LFE 0</td>
        </tr>
        <tr>
            <td>Rock</td> <td>摇滚经典</td>
            <td>-5.7</td> <td>0</td>
            <td>[1.5, -3.81, -0.2, -1.1, 0.6, 1.5, 1.91]</td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>3</td> <td>2</td> <td>ON</td> <td>5</td>
        </tr>
        <tr>
            <td>HipHop</td> <td>嘻哈音效</td>
            <td>2</td> <td>2</td>
            <td>[5.6, 5.09, 2, 0.5, -2, 1.2, 3.79, 0.5, 1.5, 4]</td>
        </tr>
        <tr>
            <td>ACG</td> <td>纯净ACG</td>
            <td>2</td> <td>3</td>
            <td>[4, 6.19, 1.5, -0.5, -0.8, 2, 5.19, 1, -1.5, 4]</td>
        </tr>
        <tr>
            <td>Folk</td> <td>民谣音效</td>
            <td>0</td> <td>1</td>
            <td>[0, 3, 0, -0.8, 1.5, 4.8, 5.8, 3.2, -0.5, 2]</td>
        </tr>
        <tr>
            <td>Classical</td> <td>婉约古风</td>
            <td>2</td> <td>2</td>
            <td>[4, 2, 0, -0.5, -1, 3.5, 4.5, 1, -1, 3]</td>
        </tr>
        <tr>
            <td rowspan=2>EQ</td>
            <td>Bass</td> <td>极重低音</td>
            <td>3</td> <td>0</td>
            <td>[6, 4.5, 3.2, 2.09, 0, 0, 0, 0, 0, 0]</td>
        </tr>
        <tr>
            <td>Vocal</td> <td>清澈人声</td>
            <td></td> <td></td>
            <td>[-1.5, -1, 0, 1.79, 4, 3.79, 1.79, 0.5, -1, 1]</td>
        </tr>
        <tr>
            <td rowspan=4>Spatial</td>
            <td>Surr</td> <td>3D环绕</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>6</td> <td>4</td> <td>ON</td> <td>1</td>
        </tr>
        <tr>
            <td>Stereo</td> <td>独享立体声</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>0</td> <td>0</td> <td>ON</td> <td>0</td>
        </tr>
        <tr>
            <td>StereoSurr</td>
            <td>环绕立体声</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>0</td> <td>0</td> <td>ON</td> <td>1</td>
        </tr>
        <tr>
            <td>StereoCrystal</td>
            <td>水晶立体声</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>0</td> <td>0</td> <td>ON</td> <td>6</td>
        </tr>
        <tr>
            <td rowspan=5>Scene</td>
            <td>Concert</td> <td>音乐厅</td>
            <td></td> <td></td> <td></td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>0</td> <td>0</td> <td>ON</td> <td>3</td>
        </tr>
        <tr>
            <td>Church</td> <td>教堂混响</td>
            <td></td> <td></td>
            <td></td>
            <td>Pattern 0, RSize 80, SDelay 40</td>
            <td>PDelay 25, DTime 2.4, HFDamping 2, Density 60, RShape 80, Q 6, Diffusion 80, SWidth 180</td>
            <td>[1] Insert 3, Curve 0, Gain -2, Freq 160, Q 1<br>[2] Insert 3, Curve 1, Gain -2.5, Freq 2000, Q 0.5<br>[3] Insert 3, Curve 2, Gain -3, Freq 8000, Q 0.5</td>
            <td>Center 0, LFE 0</td>
            <td>Dry 0, ER -15, RVB -20</td>
            <td>Front 0, Rear 0, Center 0, LFE 0</td>
        </tr>
        <tr>
            <td>Live</td> <td>演唱会现场</td>
            <td>3</td> <td>2</td>
            <td>[5.59, 5, 3, 0, -1, 0, 3.09, 4.5, 4, 5]</td>
        </tr>
        <tr>
            <td>LiveSurr</td> <td>狂嗨LIVE</td>
            <td>12</td> <td>-12</td>
            <td>[-6, -6.5, -3.7, -9.93, -12, -12, -12, -12, -12, -12]</td>
            <td>Pattern 24, RSize 50, SDelay 40</td>
            <td>PDelay 0, DTime 3.59, HFDamping 2, Density 60, RShape 40, Q 8, Diffusion 40, SWidth 110</td>
            <td>[1] Insert 3, Curve 0, Gain -1, Freq 200, Q 1<br>[2] Insert 3, Curve 1, Gain -3, Freq 2000, Q 0.5<br>[3] Insert 3, Curve 2, Gain 0, Freq 8000, Q 0.5</td>
            <td>Center 0, LFE 0</td>
            <td>Dry 0, ER -3, RVB -20</td>
            <td>Front 0, Rear 0, Center 0, LFE 0</td>
            <td>10</td> <td>10</td> <td>ON</td> <td>0</td>
        </tr>
        <tr>
            <td>Livehouse</td> <td>LiveHouse现场</td>
            <td></td> <td></td>
            <td></td>
            <td>Pattern 4, RSize 70, SDelay 40</td>
            <td>PDelay 25, DTime 1.5, HFDamping 2.79, Density 60, RShape 40, Q 8, Diffusion 80, SWidth 150</td>
            <td>[1] Insert 3, Curve 0, Gain -1, Freq 200, Q 1<br>[2] Insert 3, Curve 1, Gain -3, Freq 2000, Q 0.5<br>[3] Insert 3, Curve 2, Gain -5, Freq 8000, Q 0.5</td>
            <td>Center 0, LFE 0</td>
            <td>Dry 0, ER -23, RVB -20</td>
            <td>Front 0, Rear 0, Center 0, LFE 0</td>
        </tr>
        <tr>
            <td rowspan=3>Custom</td>
            <td>NINEONE#</td> <td>专属音效</td>
            <td></td> <td></td>
            <td>[0, 0, -1, -1, -2, 1, 2, 2, 0, 0]</td>
            <td>Pattern 4, RSize 60, SDelay 0</td>
            <td>PDelay 5, DTime 1.2, HFDamping 3.5, Density 35, RShape 40, Q 8, Diffusion 100, SWidth 180</td>
            <td>[1] Insert 3, Curve 0, Gain -1, Freq 200, Q 1<br>[2] Insert 3, Curve 1, Gain -3, Freq 2000, Q 0.5<br>[3] Insert 3, Curve 2, Gain 0, Freq 8000, Q 0.5</td>
            <td>Center 0, LFE 0</td>
            <td>Dry -1.5, ER -28, RVB -22</td>
            <td>Front 0, Rear 0, Center 0, LFE 0</td>
        </tr>
        <tr>
            <td>毛不易《小王》</td> <td>专属音效</td>
            <td></td> <td></td>
            <td>[-5, -4, -2, -0.5, 1.5, 2.5, 0, -3, -5, -5]</td>
            <td>Pattern 4, RSize 60, SDelay 0</td>
            <td>PDelay 25, DTime 1, HFDamping 2.25, Density 80, RShape 100, Q 2, Diffusion 100, SWidth 180</td>
            <td>[1] Insert 3, Curve 0, Gain -2, Freq 80, Q 0.5<br>[2] Insert 3, Curve 1, Gain 0, Freq 1000, Q 1<br>[3] Insert 3, Curve 2, Gain -2, Freq 8000, Q 0.5</td>
            <td>Center 0, LFE 0</td>
            <td>Dry 0, ER -14, RVB -80</td>
            <td>Front 0, Rear 0, Center 0, LFE 0</td>
        </tr>
        <tr>
            <td>《不完美人生指南》</td> <td>专属音效</td>
            <td></td> <td></td>
            <td>[-1, -1, -2, -3, -2, -2, -1, -1, -1, -1]</td>
            <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
            <td>2</td> <td>0.5</td> <td>OFF</td> <td>1.5</td>
        </tr>
    </thead>
</table>
