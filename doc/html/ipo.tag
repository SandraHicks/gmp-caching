<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>cachedInt.cpp</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>cachedInt_8cpp</filename>
    <includes id="cachedInt_8h" name="cachedInt.h" local="yes" imported="no">cachedInt.h</includes>
  </compound>
  <compound kind="file">
    <name>cachedInt.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>cachedInt_8h</filename>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
  </compound>
  <compound kind="file">
    <name>cachedRational.cpp</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>cachedRational_8cpp</filename>
    <includes id="cachedRational_8h" name="cachedRational.h" local="yes" imported="no">cachedRational.h</includes>
  </compound>
  <compound kind="file">
    <name>cachedRational.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>cachedRational_8h</filename>
  </compound>
  <compound kind="file">
    <name>caching_operations.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>caching__operations_8c</filename>
    <includes id="caching__operations_8h" name="caching_operations.h" local="yes" imported="no">caching_operations.h</includes>
    <includes id="mpz__caching_8h" name="mpz_caching.h" local="yes" imported="no">mpz_caching.h</includes>
    <includes id="hashtable_8h" name="hashtable.h" local="yes" imported="no">hashtable.h</includes>
    <includes id="hashing_8h" name="hashing.h" local="yes" imported="no">hashing.h</includes>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_insert_mpz_raw</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>af24ac6bfb6b961f29854a77b0fd1cdcd</anchor>
      <arglist>(lookup *lu, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_exists_mpz_raw</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a8378b6353d6fcf409299ae5d043405b2</anchor>
      <arglist>(lookup *lu, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_exists_mpz_binary_raw</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a086dd00f1d95d3876f60c660c28f4655</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2, uint64_t *extra_info, int op)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_cache</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a9d0deb4e421d3539ca702e1d25a454bc</anchor>
      <arglist>(lookup *cache, uint64_t cachesize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_cache</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a5bf3baf9276c8b7f7e04b54a6d50836e</anchor>
      <arglist>(lookup *cache)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_mpz</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a14dba9d2bb5513f288c13a42127aa5d8</anchor>
      <arglist>(lookup *cache, uint64_t id, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>get_double</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>ab916e2c8a7127d6b8d2daa5723686313</anchor>
      <arglist>(lookup *cache, uint64_t id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_mpz</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>ac054b43373a334ba0a65041d5b8d9035</anchor>
      <arglist>(uint64_t id, mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>mpz_cached_int</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a8ad24c72fe1e1e7bcb71342763573276</anchor>
      <arglist>(mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_insert_mpz</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a5be5a3ac60ee70c550943ca7210ed0ad</anchor>
      <arglist>(lookup *lu, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_exists_mpz</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a56daf76d7d1d61b8c7616dc6b4879cb4</anchor>
      <arglist>(lookup *lu, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_exists_mpz_binary</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a7c5e3db12104bd0cc6a006b02af6d68f</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2, uint64_t *extra_info, int op)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mpz_swap</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a7ea00a65df3156e97a088f4609996b1f</anchor>
      <arglist>(mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_add</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>aa98a971c3afc7ff1d3ade18670a22042</anchor>
      <arglist>(lookup *cache, mpz_t op1_in, mpz_t op2_in)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_sub</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>ade2fa50c243e70384beb751d1961708a</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_mul</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a745a92c531d7f1b4075fdedf31b970c4</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_tdiv</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>aa55ef35c74d3f9f270d3899adeaad0da</anchor>
      <arglist>(lookup *cache, uint64_t *rest, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_mod</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>aeffd662de6699ec5c8f870c70ea8e612</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_gcd</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a8ca5e7ca205dc3b211702f891d5b5f49</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_lcm</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>aa92deb9f1e48204d5c3f83b1ce77e975</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_invert</name>
      <anchorfile>caching__operations_8c.html</anchorfile>
      <anchor>a58b9d53218eca4d5c254a4500f621322</anchor>
      <arglist>(lookup *cache, mpz_t op, mpz_t mod)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>caching_operations.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>caching__operations_8h</filename>
    <includes id="hashtable_8h" name="hashtable.h" local="yes" imported="no">hashtable.h</includes>
    <includes id="mpz__caching_8h" name="mpz_caching.h" local="yes" imported="no">mpz_caching.h</includes>
    <includes id="defines_8h" name="defines.h" local="yes" imported="no">defines.h</includes>
    <class kind="struct">lookup_table</class>
    <class kind="struct">lookup_table_binary</class>
    <class kind="struct">lookup</class>
    <member kind="typedef">
      <type>struct lookup_table</type>
      <name>lookup_table</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a5f315994a3f6986c94c1cf8c1feea2fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct lookup_table_binary</type>
      <name>lookup_table_binary</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a10378a824d9fad74088e8b761bd88bd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct lookup</type>
      <name>lookup</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a54725a138fee887b27397d25e09db5d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>Operation</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ADD</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bbacfcf145f2788bf340ff3f3098bc54909</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SUB</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bba12b733d4941495e86811fe6ceeeff9da</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MUL</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bba086ab1f2f4dac104b6826ebe0eaba8fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TDIV</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bbac3e4cf6bb26322af5dcabd9a3e536863</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MOD</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bba140fcc89db148e5975f1486e794675ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>GCD</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bba1e01e015db0e95c2da032bb76f5ddcc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>LCM</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bba637e1bdd15cfca1925a9de9396e0f9bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INV</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa8f137f19095e0bdcf4f521e901f88bba003b741848d7128e25831a8376672700</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_cache</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a9d0deb4e421d3539ca702e1d25a454bc</anchor>
      <arglist>(lookup *cache, uint64_t cachesize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_cache</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a5bf3baf9276c8b7f7e04b54a6d50836e</anchor>
      <arglist>(lookup *cache)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>mpz_cached_int</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a8ad24c72fe1e1e7bcb71342763573276</anchor>
      <arglist>(mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_mpz</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>ac054b43373a334ba0a65041d5b8d9035</anchor>
      <arglist>(uint64_t id, mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_mpz</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a14dba9d2bb5513f288c13a42127aa5d8</anchor>
      <arglist>(lookup *cache, uint64_t id, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>get_double</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>ab916e2c8a7127d6b8d2daa5723686313</anchor>
      <arglist>(lookup *cache, uint64_t id)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_insert_mpz</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a5be5a3ac60ee70c550943ca7210ed0ad</anchor>
      <arglist>(lookup *lu, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_exists_mpz</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a56daf76d7d1d61b8c7616dc6b4879cb4</anchor>
      <arglist>(lookup *lu, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cache_exists_mpz_binary</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a7c5e3db12104bd0cc6a006b02af6d68f</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2, uint64_t *extra_info, int op)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_add</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa98a971c3afc7ff1d3ade18670a22042</anchor>
      <arglist>(lookup *cache, mpz_t op1_in, mpz_t op2_in)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_sub</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>ade2fa50c243e70384beb751d1961708a</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_mul</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a745a92c531d7f1b4075fdedf31b970c4</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_tdiv</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa55ef35c74d3f9f270d3899adeaad0da</anchor>
      <arglist>(lookup *cache, uint64_t *rest, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_mod</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>af76568c03fb8ccd12ff15ab71c99c6bd</anchor>
      <arglist>(lookup *cache, mpz_t op, mpz_t mod)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_lcm</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>aa92deb9f1e48204d5c3f83b1ce77e975</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_gcd</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a8ca5e7ca205dc3b211702f891d5b5f49</anchor>
      <arglist>(lookup *cache, mpz_t op1, mpz_t op2)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>cached_mpz_invert</name>
      <anchorfile>caching__operations_8h.html</anchorfile>
      <anchor>a58b9d53218eca4d5c254a4500f621322</anchor>
      <arglist>(lookup *cache, mpz_t op, mpz_t mod)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>defines.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>defines_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>cachedInt_MAX</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a4ad9728365e70dea0b97d88a14c62710</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>cachedInt_MIN</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>ad0a5ef5f0a3a61ddbc2d75a02d8e36e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>cachedInt_SIGN</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a18f2a1494a0d643f51839313f03ab1ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>cachedInt_IsID</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a4d3c17db9bb1b4c9a1a6bdf71d16195a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>hashtable_RATIO</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a1dd941e838c33dd491826fa498bc37b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NUMBER_HF</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a1d7a097d98759ea37675266376c63e99</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SHIFT</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>ac179eef68bcc694aa0ef8dd1eb09950b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NEG</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>aa27c29fc6f203aac29fb3632a0bafda5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PLUSINFTY</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a32c24060f7e736dc85153f325ccdc7e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MINUSINFTY</name>
      <anchorfile>defines_8h.html</anchorfile>
      <anchor>a20adc40cb2e8ce80a3b1241a8905e8a9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hashing.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>hashing_8c</filename>
    <includes id="defines_8h" name="defines.h" local="yes" imported="no">defines.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>FNV_64_PRIME</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a843a032e93d6d54b28933d827eb4c966</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FNV1_64_INIT</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a97c6e8016ffe540a627163d406059552</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FNV1A_64_INIT</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a1eb99785c4898f16341824639f52d50f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned __int128</type>
      <name>uint128_t</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a396787e5ec029b1205bd3e4cd9763e7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64_t</type>
      <name>Fnv64_t</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>ab6714df8881207174e4c0e0b12c32583</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_FNV1a_hash</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a2b4c88ee112b98a4964da93fb0c8ab05</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_Jenkins_hash</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a319e6314e49fb9e23fc8b1667031409a</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_lookup3_hash</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a3418cd49ff87c091e401df5c1745f8c0</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_Sip_hash</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a8c95fa7a682da0f000d85afbaaf28d83</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_Murmur_hash</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>ae1fc6aab0474de396ac9abe0ef6e6466</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_CRC_hash</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a8a8dd73303711a6884acad72b0caa968</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>Cantor_pairing_function_int64</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>af44c8e6918384ae4ab580b7b5976eca9</anchor>
      <arglist>(uint64_t v1, uint64_t v2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Cantor_pairing_function_mpz</name>
      <anchorfile>hashing_8c.html</anchorfile>
      <anchor>a6fa8f477d6b93a5a0c4753a75bd3cc8b</anchor>
      <arglist>(mpz_t v1, mpz_t v2, mpz_t res)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hashing.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>hashing_8h</filename>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_FNV1a_hash</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>a2b4c88ee112b98a4964da93fb0c8ab05</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_Jenkins_hash</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>a319e6314e49fb9e23fc8b1667031409a</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_lookup3_hash</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>a3418cd49ff87c091e401df5c1745f8c0</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_Sip_hash</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>a8c95fa7a682da0f000d85afbaaf28d83</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_Murmur_hash</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>ae1fc6aab0474de396ac9abe0ef6e6466</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>get_CRC_hash</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>a8a8dd73303711a6884acad72b0caa968</anchor>
      <arglist>(mpz_t myval)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Cantor_pairing_function_mpz</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>a6fa8f477d6b93a5a0c4753a75bd3cc8b</anchor>
      <arglist>(mpz_t v1, mpz_t v2, mpz_t res)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>Cantor_pairing_function_int64</name>
      <anchorfile>hashing_8h.html</anchorfile>
      <anchor>af44c8e6918384ae4ab580b7b5976eca9</anchor>
      <arglist>(uint64_t v1, uint64_t v2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hashtable.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>hashtable_8c</filename>
    <includes id="hashtable_8h" name="hashtable.h" local="yes" imported="no">hashtable.h</includes>
    <includes id="hashing_8h" name="hashing.h" local="yes" imported="no">hashing.h</includes>
    <includes id="mpz__caching_8h" name="mpz_caching.h" local="yes" imported="no">mpz_caching.h</includes>
    <member kind="function">
      <type>void</type>
      <name>init_hashtable</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a8f4aa8473391505b303072098b101285</anchor>
      <arglist>(Hashtable *ht, uint64_t size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_hashtable</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a31e50f67c07fb1a475268694bfd5743d</anchor>
      <arglist>(Hashtable *ht)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_element</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a3999323c0facade24699b869058ddeb7</anchor>
      <arglist>(Hashtable *ht, uint64_t id, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>exists_element</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>aa2cdb80b044d66f091e6cad114e633b9</anchor>
      <arglist>(Hashtable *ht, uint64_t *hashes, mpz_t element, mpz_t_cache *cache)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_k_hashes</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a7198d8653365a8e7b187bbcb49bab4aa</anchor>
      <arglist>(mpz_t val, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_k_hashes_cpf</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>af267b5c3e0669ad9844482299eb9dce0</anchor>
      <arglist>(mpz_t val1, mpz_t val2, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_hashtable_binary</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a1758c25104d2433ec0fb68861baaa330</anchor>
      <arglist>(Hashtable_binary *ht, uint64_t size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_hashtable_binary</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a99e3e52694edc6e5396bc93bcdb2d0eb</anchor>
      <arglist>(Hashtable_binary *ht)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_element_binary</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a8d6049bccb0ee7c582dd8190c9e0530d</anchor>
      <arglist>(Hashtable_binary *ht, uint64_t id_op1, uint64_t id_op2, uint64_t id_res, uint64_t *extra_info, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>exists_element_binary</name>
      <anchorfile>hashtable_8c.html</anchorfile>
      <anchor>a640832720182207089e4e7156ffcac6d</anchor>
      <arglist>(Hashtable_binary *ht, uint64_t *hashes, mpz_t op1, mpz_t op2, mpz_t_cache *cache, uint64_t *extra_info)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hashtable.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>hashtable_8h</filename>
    <includes id="defines_8h" name="defines.h" local="yes" imported="no">defines.h</includes>
    <includes id="mpz__caching_8h" name="mpz_caching.h" local="yes" imported="no">mpz_caching.h</includes>
    <class kind="struct">cachedIntElement</class>
    <class kind="struct">cachedIntList</class>
    <class kind="struct">Hashtable</class>
    <class kind="struct">cachedIntElement_binary</class>
    <class kind="struct">cachedIntList_binary</class>
    <class kind="struct">Hashtable_binary</class>
    <member kind="typedef">
      <type>struct cachedIntElement</type>
      <name>cachedIntElement</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a44bf679bfa4c7678ebfd153172bb5268</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct cachedIntList</type>
      <name>cachedIntList</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a50866be81e04ce297cac4ded795314b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct Hashtable</type>
      <name>Hashtable</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a9ef29b69618421bbfaad15efeea75201</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct cachedIntElement_binary</type>
      <name>cachedIntElement_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a6c52337ae6ced738d9ad1044c62d821e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct cachedIntList_binary</type>
      <name>cachedIntList_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a051c88e7c88c188a75b017f2dab2031c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct Hashtable_binary</type>
      <name>Hashtable_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a54f40ceb8fdc52f64990012096a7c7b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_hashtable</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a8f4aa8473391505b303072098b101285</anchor>
      <arglist>(Hashtable *ht, uint64_t size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_hashtable</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a31e50f67c07fb1a475268694bfd5743d</anchor>
      <arglist>(Hashtable *ht)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_element</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a3999323c0facade24699b869058ddeb7</anchor>
      <arglist>(Hashtable *ht, uint64_t id, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>exists_element</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>aa2cdb80b044d66f091e6cad114e633b9</anchor>
      <arglist>(Hashtable *ht, uint64_t *hashes, mpz_t element, mpz_t_cache *cache)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_k_hashes</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a7198d8653365a8e7b187bbcb49bab4aa</anchor>
      <arglist>(mpz_t val, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_hashtable_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a1758c25104d2433ec0fb68861baaa330</anchor>
      <arglist>(Hashtable_binary *ht, uint64_t size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_hashtable_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a99e3e52694edc6e5396bc93bcdb2d0eb</anchor>
      <arglist>(Hashtable_binary *ht)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_element_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a8d6049bccb0ee7c582dd8190c9e0530d</anchor>
      <arglist>(Hashtable_binary *ht, uint64_t id_op1, uint64_t id_op2, uint64_t id_res, uint64_t *extra_info, uint64_t *hashes)</arglist>
    </member>
    <member kind="function">
      <type>uint64_t</type>
      <name>exists_element_binary</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>a640832720182207089e4e7156ffcac6d</anchor>
      <arglist>(Hashtable_binary *ht, uint64_t *hashes, mpz_t op1, mpz_t op2, mpz_t_cache *cache, uint64_t *extra_info)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_k_hashes_cpf</name>
      <anchorfile>hashtable_8h.html</anchorfile>
      <anchor>af267b5c3e0669ad9844482299eb9dce0</anchor>
      <arglist>(mpz_t val1, mpz_t val2, uint64_t *hashes)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>master_cache_integer.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>master__cache__integer_8c</filename>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
    <includes id="master__cache__integer_8h" name="master_cache_integer.h" local="yes" imported="no">master_cache_integer.h</includes>
    <includes id="caching__operations_8h" name="caching_operations.h" local="yes" imported="no">caching_operations.h</includes>
    <includes id="overflow__detection_8h" name="overflow_detection.h" local="yes" imported="no">overflow_detection.h</includes>
    <member kind="function">
      <type>void</type>
      <name>get_mpz_from_id</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a571d2709b7ba70de2e4e7a6027215f0e</anchor>
      <arglist>(MasterCache *mstr, cachedInt id, mpz_t mpz)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_add</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>acf48c6c064be125bfc2e3daf62f10177</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_mul</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>aa558a557fa5371fc35597dc52fd824e5</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_div</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a7cbe579aa33d35c4042fac942fed2070</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_mod</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>abe0e4d423323534bba705a0e6fed30dc</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_gcd</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a663303ff03efc5249b8aa408ff5cce29</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_lcm</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>ac189c1e54bc54e033333d7cd5371d46f</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_abs</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a9b1af0e5f31c36a672ce4774aec4e54f</anchor>
      <arglist>(cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>direct_invert</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>aae7d64a848078cd497869680dbca4780</anchor>
      <arglist>(cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ext_euclid</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a66c8c57579e8806ff904aeb71d54ec44</anchor>
      <arglist>(cachedInt val1, cachedInt val2, cachedInt *d, cachedInt *s, cachedInt *t)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_init_cache</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a4ee9f3ad2e81f1b21c1c0c47aa52b270</anchor>
      <arglist>(MasterCache **mstr, uint64_t cachesize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_clear_cache</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a63c4967e9b2432632f4215488e49195b</anchor>
      <arglist>(MasterCache **mstr)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_set</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a2e8ed43761ae3945335b89102db422fd</anchor>
      <arglist>(MasterCache *mstr, mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_get</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a70e68c14bd00b07597b31dba34aba997</anchor>
      <arglist>(MasterCache *mstr, cachedInt id, mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>cached_int_get_d</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>af0c42f55a0674b42df4ce45322c33198</anchor>
      <arglist>(MasterCache *mstr, cachedInt id)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_neg</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a0554d6cc2b779f43cacb2d1fe95efdc2</anchor>
      <arglist>(MasterCache *mstr, cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_abs</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a156b95f33adc0b39fc5b37c86023028a</anchor>
      <arglist>(MasterCache *mstr, cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>cached_int_sgn</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a398a6b9dd17c9e3e457184f8f7f417f2</anchor>
      <arglist>(MasterCache *mstr, cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_add</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a2c77389b27a3a9c47f580cc52b6bbe62</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_sub</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>af3fa99a34d3f8f474ca5cb1caf45b0dc</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_mul</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a418f697aefb1a082369940b69ef21758</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_tdiv</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>a65de9b96c7568d2a4bc8a6a05749be04</anchor>
      <arglist>(MasterCache *mstr, cachedInt divident, cachedInt divisor, cachedInt *rest)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_mod</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>ac95bf4ec8ac8cdfc09f81dc6ab3f7954</anchor>
      <arglist>(MasterCache *mstr, cachedInt number, cachedInt n)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_gcd</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>aee6e62d1fc9500706bd768db8e2a5af3</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_lcm</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>aa220bc67a8c28874c008e7558cbec79d</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>cached_int_invert</name>
      <anchorfile>master__cache__integer_8c.html</anchorfile>
      <anchor>aaabedd43537e5425aebea90933ccaa75</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2, cachedInt *result)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>master_cache_integer.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>master__cache__integer_8h</filename>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
    <member kind="function">
      <type>void</type>
      <name>cached_int_init_cache</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a4ee9f3ad2e81f1b21c1c0c47aa52b270</anchor>
      <arglist>(MasterCache **mstr, uint64_t cachesize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_clear_cache</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a63c4967e9b2432632f4215488e49195b</anchor>
      <arglist>(MasterCache **mstr)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_set</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a2e8ed43761ae3945335b89102db422fd</anchor>
      <arglist>(MasterCache *mstr, mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_int_get</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a70e68c14bd00b07597b31dba34aba997</anchor>
      <arglist>(MasterCache *mstr, cachedInt id, mpz_t number)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>cached_int_get_d</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>af0c42f55a0674b42df4ce45322c33198</anchor>
      <arglist>(MasterCache *mstr, cachedInt id)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_abs</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a156b95f33adc0b39fc5b37c86023028a</anchor>
      <arglist>(MasterCache *mstr, cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_neg</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a0554d6cc2b779f43cacb2d1fe95efdc2</anchor>
      <arglist>(MasterCache *mstr, cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>cached_int_sgn</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a398a6b9dd17c9e3e457184f8f7f417f2</anchor>
      <arglist>(MasterCache *mstr, cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_add</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a2c77389b27a3a9c47f580cc52b6bbe62</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_sub</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>af3fa99a34d3f8f474ca5cb1caf45b0dc</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_mul</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a418f697aefb1a082369940b69ef21758</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_tdiv</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>a65de9b96c7568d2a4bc8a6a05749be04</anchor>
      <arglist>(MasterCache *mstr, cachedInt divident, cachedInt divisor, cachedInt *rest)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_mod</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>ac95bf4ec8ac8cdfc09f81dc6ab3f7954</anchor>
      <arglist>(MasterCache *mstr, cachedInt number, cachedInt n)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_gcd</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>aee6e62d1fc9500706bd768db8e2a5af3</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>cached_int_lcm</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>aa220bc67a8c28874c008e7558cbec79d</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>cached_int_invert</name>
      <anchorfile>master__cache__integer_8h.html</anchorfile>
      <anchor>aaabedd43537e5425aebea90933ccaa75</anchor>
      <arglist>(MasterCache *mstr, cachedInt val1, cachedInt val2, cachedInt *result)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>master_cache_rational.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>master__cache__rational_8c</filename>
    <includes id="defines_8h" name="defines.h" local="yes" imported="no">defines.h</includes>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
    <includes id="master__cache__rational_8h" name="master_cache_rational.h" local="yes" imported="no">master_cache_rational.h</includes>
    <includes id="master__cache__integer_8h" name="master_cache_integer.h" local="yes" imported="no">master_cache_integer.h</includes>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_set</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>aafcd96ffb4f1982192696a84480eec9a</anchor>
      <arglist>(MasterCache *mstr, mpz_t counter, mpz_t denominator)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_set_mpq</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>aebbcc317ee4d0ddf591a0133685bb7f5</anchor>
      <arglist>(MasterCache *mstr, mpq_t number)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_set_cached</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a76f7529a1cfce6321f0e9acfcfd9cd5c</anchor>
      <arglist>(MasterCache *mstr, cachedInt counter, cachedInt denominator)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reset</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a02240fa4a43aba01ca1002d607f531d6</anchor>
      <arglist>(MasterCache *mstr, mpz_t counter, mpz_t denominator, cachedRational *value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reset_mpq</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>ac09bde1d4e9c80fcc0f6d8a010a4f450</anchor>
      <arglist>(MasterCache *mstr, mpq_t number, cachedRational *value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reset_cached</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a259c99e89785d15c79d51ffb9c9e6ece</anchor>
      <arglist>(MasterCache *mstr, cachedInt counter, cachedInt denominator, cachedRational *value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_get</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a5b456f687d953c2c656969de0a13dd13</anchor>
      <arglist>(MasterCache *mstr, cachedRational *id, mpz_t counter, mpz_t denominator)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_get_mpq</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>afc815744e1ee8fe59c0fe8659d09821d</anchor>
      <arglist>(MasterCache *mstr, cachedRational *id, mpq_t number)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>cached_rational_get_d</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a730ec1ddcbbef0cd1855c930d0615e90</anchor>
      <arglist>(MasterCache *mstr, cachedRational *id)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_add</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>ad2e8b5adb77e0da7b287c65cbfdd5f6f</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reduce_inplace</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>aefd009fd65e95dd1318dd3263b150f12</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_reduce</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a5ca6f556d5829bf6146c2ef70ec12a76</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_sub</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>af56650361ac0a50dec1c8339b2d63a78</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_mul</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a3d9ea13255b254a7eea5604573b54083</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_div</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>af87cafcad9565ebccb92ea78f2487a9a</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_abs</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>ad9c400a7fb516b9440c845251555b103</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_inv</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a4103eadf67188467b1c4faae7ef8e852</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_neg_inplace</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a62e7f9ad81746c5536945cf5a86f3117</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_neg</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>af6ecb2e2731332648fd4601d0ca8882c</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>cached_rational_sgn</name>
      <anchorfile>master__cache__rational_8c.html</anchorfile>
      <anchor>a03bf1a170c0462446d55bfebcaf36375</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>master_cache_rational.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>master__cache__rational_8h</filename>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_set</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>aafcd96ffb4f1982192696a84480eec9a</anchor>
      <arglist>(MasterCache *mstr, mpz_t counter, mpz_t denominator)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_set_mpq</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>aebbcc317ee4d0ddf591a0133685bb7f5</anchor>
      <arglist>(MasterCache *mstr, mpq_t number)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_set_cached</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a76f7529a1cfce6321f0e9acfcfd9cd5c</anchor>
      <arglist>(MasterCache *mstr, cachedInt counter, cachedInt denominator)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reset_mpq</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>ac09bde1d4e9c80fcc0f6d8a010a4f450</anchor>
      <arglist>(MasterCache *mstr, mpq_t number, cachedRational *value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reset</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a02240fa4a43aba01ca1002d607f531d6</anchor>
      <arglist>(MasterCache *mstr, mpz_t counter, mpz_t denominator, cachedRational *value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reset_cached</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a259c99e89785d15c79d51ffb9c9e6ece</anchor>
      <arglist>(MasterCache *mstr, cachedInt counter, cachedInt denominator, cachedRational *value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_get</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a5b456f687d953c2c656969de0a13dd13</anchor>
      <arglist>(MasterCache *mstr, cachedRational *id, mpz_t counter, mpz_t denominator)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_get_mpq</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>afc815744e1ee8fe59c0fe8659d09821d</anchor>
      <arglist>(MasterCache *mstr, cachedRational *id, mpq_t number)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>cached_rational_get_d</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a730ec1ddcbbef0cd1855c930d0615e90</anchor>
      <arglist>(MasterCache *mstr, cachedRational *id)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_add</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>ad2e8b5adb77e0da7b287c65cbfdd5f6f</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_reduce</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a5ca6f556d5829bf6146c2ef70ec12a76</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_reduce_inplace</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>aefd009fd65e95dd1318dd3263b150f12</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_sub</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>af56650361ac0a50dec1c8339b2d63a78</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_mul</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a3d9ea13255b254a7eea5604573b54083</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_div</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>af87cafcad9565ebccb92ea78f2487a9a</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val1, cachedRational *val2)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_abs</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>ad9c400a7fb516b9440c845251555b103</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_inv</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a4103eadf67188467b1c4faae7ef8e852</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>cachedRational</type>
      <name>cached_rational_neg</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>af6ecb2e2731332648fd4601d0ca8882c</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cached_rational_neg_inplace</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a62e7f9ad81746c5536945cf5a86f3117</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>cached_rational_sgn</name>
      <anchorfile>master__cache__rational_8h.html</anchorfile>
      <anchor>a03bf1a170c0462446d55bfebcaf36375</anchor>
      <arglist>(MasterCache *mstr, cachedRational *val)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mastercache.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>mastercache_8c</filename>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
    <includes id="master__cache__integer_8h" name="master_cache_integer.h" local="yes" imported="no">master_cache_integer.h</includes>
    <member kind="function">
      <type>void</type>
      <name>cache_init</name>
      <anchorfile>mastercache_8c.html</anchorfile>
      <anchor>accbfa6ac43f1e13d51334d10e35cac0e</anchor>
      <arglist>(MasterCache **mstr, uint64_t cache_size)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mastercache.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>mastercache_8h</filename>
    <includes id="defines_8h" name="defines.h" local="yes" imported="no">defines.h</includes>
    <includes id="caching__operations_8h" name="caching_operations.h" local="yes" imported="no">caching_operations.h</includes>
    <class kind="struct">MasterCacheInt</class>
    <class kind="struct">MasterCache</class>
    <class kind="struct">cache_rational</class>
    <member kind="typedef">
      <type>struct MasterCacheInt</type>
      <name>MasterCacheInt</name>
      <anchorfile>mastercache_8h.html</anchorfile>
      <anchor>a36a548913d4fa7ddfc3b5ab7bdc13ccd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct MasterCache</type>
      <name>MasterCache</name>
      <anchorfile>mastercache_8h.html</anchorfile>
      <anchor>ad193fc2757a525675885e0a4cc7b01f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64_t</type>
      <name>cachedInt</name>
      <anchorfile>mastercache_8h.html</anchorfile>
      <anchor>a113c03970467afb459ed5ae157d0a870</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct cache_rational</type>
      <name>cachedRational</name>
      <anchorfile>mastercache_8h.html</anchorfile>
      <anchor>a273202caad9157b97f14a5b3cb4ca1b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cache_init</name>
      <anchorfile>mastercache_8h.html</anchorfile>
      <anchor>accbfa6ac43f1e13d51334d10e35cac0e</anchor>
      <arglist>(MasterCache **mstr, uint64_t cache_size)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mpz_caching.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>mpz__caching_8c</filename>
    <includes id="mpz__caching_8h" name="mpz_caching.h" local="yes" imported="no">mpz_caching.h</includes>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
    <member kind="function">
      <type>void</type>
      <name>init_mpz_cache</name>
      <anchorfile>mpz__caching_8c.html</anchorfile>
      <anchor>af5387ca483d290f5da20649239c5fdef</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_mpz_cache</name>
      <anchorfile>mpz__caching_8c.html</anchorfile>
      <anchor>aad2ec516965e5bd06eb4ed91a9707775</anchor>
      <arglist>(mpz_t_cache *cache)</arglist>
    </member>
    <member kind="function">
      <type>int64_t</type>
      <name>insert_mpz</name>
      <anchorfile>mpz__caching_8c.html</anchorfile>
      <anchor>ab93e1f89e6a97ba347b58bd7955d02ba</anchor>
      <arglist>(mpz_t_cache *cache, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printEntry</name>
      <anchorfile>mpz__caching_8c.html</anchorfile>
      <anchor>a4ea9e1949f05c8ed0fa17421e156d7ba</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t i)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_cached_mpz</name>
      <anchorfile>mpz__caching_8c.html</anchorfile>
      <anchor>acfb7f476b995041bb4ba41e31f5220ae</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t i, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>get_cached_double</name>
      <anchorfile>mpz__caching_8c.html</anchorfile>
      <anchor>a1afc9ada65a26e6562e7eb6b24064f72</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t i)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>mpz_caching.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>mpz__caching_8h</filename>
    <class kind="struct">cached_mpz_t</class>
    <class kind="struct">mpz_t_cache</class>
    <member kind="typedef">
      <type>struct cached_mpz_t</type>
      <name>cached_mpz_t</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>a43691d5ed6539a74f75fcbb2eeb01d8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>struct mpz_t_cache</type>
      <name>mpz_t_cache</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>a084f99de7821a83cdca8d0f747cd6484</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init_mpz_cache</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>af5387ca483d290f5da20649239c5fdef</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delete_mpz_cache</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>aad2ec516965e5bd06eb4ed91a9707775</anchor>
      <arglist>(mpz_t_cache *cache)</arglist>
    </member>
    <member kind="function">
      <type>int64_t</type>
      <name>insert_mpz</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>ab93e1f89e6a97ba347b58bd7955d02ba</anchor>
      <arglist>(mpz_t_cache *cache, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>printEntry</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>a4ea9e1949f05c8ed0fa17421e156d7ba</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t i)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_cached_mpz</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>acfb7f476b995041bb4ba41e31f5220ae</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t i, mpz_t val)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>get_cached_double</name>
      <anchorfile>mpz__caching_8h.html</anchorfile>
      <anchor>a1afc9ada65a26e6562e7eb6b24064f72</anchor>
      <arglist>(mpz_t_cache *cache, uint64_t i)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>overflow_detection.c</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>overflow__detection_8c</filename>
    <includes id="overflow__detection_8h" name="overflow_detection.h" local="yes" imported="no">overflow_detection.h</includes>
    <includes id="defines_8h" name="defines.h" local="yes" imported="no">defines.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>MAXBIT</name>
      <anchorfile>overflow__detection_8c.html</anchorfile>
      <anchor>af3694ae57103552f7fba8b94e114a90f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>uint32_t</type>
      <name>MSB</name>
      <anchorfile>overflow__detection_8c.html</anchorfile>
      <anchor>ab9ebfca4f389fbfd7518c73802739dfa</anchor>
      <arglist>(cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>cachedInt</type>
      <name>deleteIdBit</name>
      <anchorfile>overflow__detection_8c.html</anchorfile>
      <anchor>a069c125ad06465b64cbfe809b29ec9ce</anchor>
      <arglist>(cachedInt val)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>additionOverflow</name>
      <anchorfile>overflow__detection_8c.html</anchorfile>
      <anchor>a9353ddb1f8619095dfce206ab4209d3a</anchor>
      <arglist>(cachedInt op1, cachedInt op2)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>multiplicationOverflow</name>
      <anchorfile>overflow__detection_8c.html</anchorfile>
      <anchor>a3d152657eff6ecfd62713f7252beb0fe</anchor>
      <arglist>(cachedInt op1, cachedInt op2)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>exponentiationOverflow</name>
      <anchorfile>overflow__detection_8c.html</anchorfile>
      <anchor>a3f5d390da9ae4425c7ba83964f3b0905</anchor>
      <arglist>(cachedInt base, cachedInt exp)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>overflow_detection.h</name>
    <path>/home/sandra/Documents/HiWi/GMPCache/gmp-caching/src/</path>
    <filename>overflow__detection_8h</filename>
    <includes id="mastercache_8h" name="mastercache.h" local="yes" imported="no">mastercache.h</includes>
    <member kind="function">
      <type>int</type>
      <name>additionOverflow</name>
      <anchorfile>overflow__detection_8h.html</anchorfile>
      <anchor>a9353ddb1f8619095dfce206ab4209d3a</anchor>
      <arglist>(cachedInt op1, cachedInt op2)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>multiplicationOverflow</name>
      <anchorfile>overflow__detection_8h.html</anchorfile>
      <anchor>a3d152657eff6ecfd62713f7252beb0fe</anchor>
      <arglist>(cachedInt op1, cachedInt op2)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>exponentiationOverflow</name>
      <anchorfile>overflow__detection_8h.html</anchorfile>
      <anchor>a3f5d390da9ae4425c7ba83964f3b0905</anchor>
      <arglist>(cachedInt base, cachedInt exp)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>cache_rational</name>
    <filename>structcache__rational.html</filename>
    <member kind="variable">
      <type>cachedInt</type>
      <name>counter</name>
      <anchorfile>structcache__rational.html</anchorfile>
      <anchor>a15e5babd329dba0f66c798cc95fbe588</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedInt</type>
      <name>denominator</name>
      <anchorfile>structcache__rational.html</anchorfile>
      <anchor>af5ea8cbe1779ca6bfc5c1724b295bb43</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>cached_mpz_t</name>
    <filename>structcached__mpz__t.html</filename>
    <member kind="variable">
      <type>mpz_t</type>
      <name>integer</name>
      <anchorfile>structcached__mpz__t.html</anchorfile>
      <anchor>ac583570461b183678dd9223ecf0a8cfd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>fp</name>
      <anchorfile>structcached__mpz__t.html</anchorfile>
      <anchor>a60b47a7eec98eaa5f98316e5fe1c9724</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>cachedIntElement</name>
    <filename>structcachedIntElement.html</filename>
    <member kind="variable">
      <type>uint64_t</type>
      <name>id</name>
      <anchorfile>structcachedIntElement.html</anchorfile>
      <anchor>acda821458cfe34dda3bff8b7b0373fb9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>hash</name>
      <anchorfile>structcachedIntElement.html</anchorfile>
      <anchor>a20d62592d37c7e8c91449f534431aeb9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntElement *</type>
      <name>next</name>
      <anchorfile>structcachedIntElement.html</anchorfile>
      <anchor>ae64f5fae8aa27243af30ef13cb3ebce6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntElement *</type>
      <name>prev</name>
      <anchorfile>structcachedIntElement.html</anchorfile>
      <anchor>a90b30c8883b80e42fbf59fbc1bc8727a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>cachedIntElement_binary</name>
    <filename>structcachedIntElement__binary.html</filename>
    <member kind="variable">
      <type>uint64_t</type>
      <name>op1</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>aa4305da16240730699f33560c0f5aef0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>op2</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>aff3a2ddce9bbb4e3e9c8621da7f23799</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>result</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>a44ef9752977222f618137d8c1d6d4159</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>extra_info</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>a61b3637cb5d56531c17cc07aff0b8f84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>hash</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>ad9d23892ecafef09a352699e01aebecc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntElement_binary *</type>
      <name>next</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>a500da0d9af2a1138003bf6b6f0c22555</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntElement_binary *</type>
      <name>prev</name>
      <anchorfile>structcachedIntElement__binary.html</anchorfile>
      <anchor>ae0a95ff1f3a3062e706d06877014e8a6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>cachedIntList</name>
    <filename>structcachedIntList.html</filename>
    <member kind="variable">
      <type>cachedIntElement *</type>
      <name>head</name>
      <anchorfile>structcachedIntList.html</anchorfile>
      <anchor>ac4cce5e5d07c4b23683046e77a0fbe6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntElement *</type>
      <name>tail</name>
      <anchorfile>structcachedIntList.html</anchorfile>
      <anchor>adbe1df126c4425546e3a2b4366784c9d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>cachedIntList_binary</name>
    <filename>structcachedIntList__binary.html</filename>
    <member kind="variable">
      <type>cachedIntElement_binary *</type>
      <name>head</name>
      <anchorfile>structcachedIntList__binary.html</anchorfile>
      <anchor>ab51ea19cb68af38612cad45b08d9239f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntElement_binary *</type>
      <name>tail</name>
      <anchorfile>structcachedIntList__binary.html</anchorfile>
      <anchor>ad92905f1242fc89c700572d0d510c17f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Hashtable</name>
    <filename>structHashtable.html</filename>
    <member kind="variable">
      <type>int *</type>
      <name>counter</name>
      <anchorfile>structHashtable.html</anchorfile>
      <anchor>a99f7c11aa20bbd066528843438a42958</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntList *</type>
      <name>lists</name>
      <anchorfile>structHashtable.html</anchorfile>
      <anchor>ac4140ebb0209a40547999cce896fe17c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>size</name>
      <anchorfile>structHashtable.html</anchorfile>
      <anchor>aab81586954ce81cc3d52b41cf5ec5a04</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Hashtable_binary</name>
    <filename>structHashtable__binary.html</filename>
    <member kind="variable">
      <type>int *</type>
      <name>counter</name>
      <anchorfile>structHashtable__binary.html</anchorfile>
      <anchor>a84f8baf046a4f7a75a405e8fd448bac8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>cachedIntList_binary *</type>
      <name>lists</name>
      <anchorfile>structHashtable__binary.html</anchorfile>
      <anchor>a6c33200915e4022c6c561f35fc36d4e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>size</name>
      <anchorfile>structHashtable__binary.html</anchorfile>
      <anchor>a2232ebf98285e8d0154badb1db51fdc5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>lookup</name>
    <filename>structlookup.html</filename>
    <member kind="variable">
      <type>lookup_table *</type>
      <name>lkup</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>aac4b32e67de7870ed7ef9da8077faf3d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>add</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>ada52eb4221d2d2ab592f13e57936dad2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>sub</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>a6847e05562a081e06e25d33ac8a205a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>mul</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>aab703d9a300ea104f80a39416e512041</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>tdiv</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>abef492b10c81737d02dae892da38719a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>mod</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>aec682b8433afc9c027849a48f051af95</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>gcd</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>aaadaeeb9f694301aec3fe2c275c6201f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>lcm</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>ac00706d18994616cb35d0f4b44e04fbb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>lookup_table_binary *</type>
      <name>inv</name>
      <anchorfile>structlookup.html</anchorfile>
      <anchor>aad2f4d538e0e689ac57e456b65f36913</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>lookup_table</name>
    <filename>structlookup__table.html</filename>
    <member kind="variable">
      <type>Hashtable *</type>
      <name>ht</name>
      <anchorfile>structlookup__table.html</anchorfile>
      <anchor>a2066d36e3a0f245e7f428f1e951cd947</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>mpz_t_cache *</type>
      <name>cache</name>
      <anchorfile>structlookup__table.html</anchorfile>
      <anchor>a120547b02b115a402c758cf630ed22b1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>lookup_table_binary</name>
    <filename>structlookup__table__binary.html</filename>
    <member kind="variable">
      <type>Hashtable_binary *</type>
      <name>ht</name>
      <anchorfile>structlookup__table__binary.html</anchorfile>
      <anchor>ae12894f1b36d77b08582558701d25029</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>mpz_t_cache *</type>
      <name>cache</name>
      <anchorfile>structlookup__table__binary.html</anchorfile>
      <anchor>ad68f0a417fc2f1e237bfc5077d5f68c6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>MasterCache</name>
    <filename>structMasterCache.html</filename>
    <member kind="variable">
      <type>MasterCacheInt *</type>
      <name>_integers</name>
      <anchorfile>structMasterCache.html</anchorfile>
      <anchor>a5c3a0aa848b8d98114902f674e111dc3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>MasterCacheInt</name>
    <filename>structMasterCacheInt.html</filename>
    <member kind="variable">
      <type>lookup *</type>
      <name>cache</name>
      <anchorfile>structMasterCacheInt.html</anchorfile>
      <anchor>a4e80ed8be2db43aa586a75118a62606a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>mpz_t_cache</name>
    <filename>structmpz__t__cache.html</filename>
    <member kind="variable">
      <type>cached_mpz_t *</type>
      <name>cache</name>
      <anchorfile>structmpz__t__cache.html</anchorfile>
      <anchor>a68ba0b84ae67ae594f539b466dac5008</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>next_id</name>
      <anchorfile>structmpz__t__cache.html</anchorfile>
      <anchor>ad8f52046ab32c2b94ca4a32f22b4beb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64_t</type>
      <name>size</name>
      <anchorfile>structmpz__t__cache.html</anchorfile>
      <anchor>a00982c72af6f0784f31c8d28bb56fbf8</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
